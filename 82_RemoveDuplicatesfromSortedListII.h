/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:
Input: 1->1->1->2->3
Output: 2->3
*/
// Solution1: mySolution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        int last = INT_MAX;
        while(head && head->next)
        {
            if(head->val != head->next->val && head->val != last)
            {
                cur->next = head;
                cur = cur->next;
                last = head->val;  // -2147483648->2147483647->2
                head = head->next;
            }
            else if(head->val == head->next->val)
            {
                last = head->next->val;
                head = head->next->next;
            }
            else
            {
                last = head->val;
                head = head->next;
            }
        }
        if(head && head->val != last)
        {
            cur->next = head;
            cur = cur->next;
            head = head->next;
        }
        cur->next = NULL;  // 1->2->2
        return (cur == dummy) ? NULL : dummy->next;  // 1->1
    }
};*/

// Solution2:
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur;
        while(pre->next)
        {
            cur = pre->next;
            while(cur->next && cur->val == cur->next->val)
                cur = cur->next;
            if(cur != pre->next)
                pre->next = cur->next;
            else
                pre = pre->next;
        }
        return dummy->next;
    }
};
