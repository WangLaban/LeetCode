/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
/*
Time complexity : O(kN) where k is the number of linked lists.
We can merge two sorted linked list in O(n) time where n is the total number of nodes in two lists.
Sum up the merge process and we can get: O(kN).
Space complexity : O(1)
We can merge two sorted linked list in O(1) space. 
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* mergeTwoLists(ListNode* List1, ListNode* List2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *head = dummy;
    ListNode *test = dummy;
    while(List1 && List2)
    {
        if(List1->val < List2->val)
        {
            dummy->next = List1;
            List1 = List1->next;
        }
        else
        {
            dummy->next = List2;
            List2 = List2->next;
        }
        dummy = dummy->next;
    }
    if(List1)
        dummy->next = List1;
    if(List2)
        dummy->next = List2;

    return head->next;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        ListNode *test = dummy;
        
        dummy->next = lists[0];

        for(int i = 1; i < lists.size(); i++)
        {
            dummy->next = mergeTwoLists(dummy->next, lists[i]);
        }
        return head->next;
    }
};
