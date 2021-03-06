/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
/*
Time complexity : O(max(m,n)). Assume that mm and nn represents the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times.
Space complexity : O(max(m,n)). The length of the new list is at most max(m,n)+1. 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *outList = new ListNode(0);  //Construction initiation, the node is not used, so any Int type value is OK
        ListNode *curr = outList;
        int carry = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        if(carry > 0)
            curr->next = new ListNode(carry);
        
        return outList->next;
    }
};
