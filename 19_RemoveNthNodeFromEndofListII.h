/*
Given a linked list, remove the n-th node from the end of list and return its head.
Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Follow up:
Could you do this in one pass?
*/
/*
Time complexity : O(L).
The algorithm makes one traversal of the list of L nodes. Therefore time complexity is O(L).
Space complexity : O(1). We only used constant extra space.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *first = dummy;
        ListNode *second = dummy;
        //for(int i = 0; i <= n && first != NULL; i++)
        for(int i = 0; i <= n; i++)
        {
            first = first->next;
        }
        while(first != NULL)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};
