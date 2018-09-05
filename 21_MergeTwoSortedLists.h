/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Solution1: mySolution
/*class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                dummy->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                dummy->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            dummy = dummy->next;
        }
        while(l1 != NULL)
        {
            dummy->next = new ListNode(l1->val);
            l1 = l1->next;
            dummy = dummy->next;
        }
        while(l2 != NULL)
        {
            dummy->next = new ListNode(l2->val);
            l2 = l2->next;
            dummy = dummy->next;
        }
        
        return head->next;
    }
};*/
//Solution2:
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1) tail->next = l1;
        if(l2) tail->next = l2;
        
        return dummy.next;
    }
};
