/*
Given a sorted linked list, delete all duplicates such that each element appear only once.
Example 1:
Input: 1->1->2
Output: 1->2
Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // Solution1:
/*class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        while(head)
        {
            while(head->next && head->val == head->next->val)
                head = head->next;
            cur->next = head;
            cur = cur->next;
            head = head->next;
        }
        return dummy->next;
    }
};*/

// Solution2:
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        ListNode *cur = head;
        while(cur && cur->next)
        {
            if(cur->val == cur->next->val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return head;
    }
};
