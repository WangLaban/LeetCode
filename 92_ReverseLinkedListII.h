/*
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ≤ m ≤ n ≤ length of list.
Example:
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Solution: refer to https://www.jianshu.com/p/fbe6012c9e52
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *cur = NULL, *front = NULL;
        for(int i = 0; i < m - 1; i++)
            prev = prev->next;
        cur = prev->next;
        front = cur->next;
        for(int i = m; i < n; i++)
        {
            cur->next = front->next;
            front->next = prev->next;
            prev->next = front;
            front = cur->next;
        }
        return dummy->next;
    }
};
