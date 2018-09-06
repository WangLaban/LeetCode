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
Time complexity : O(Nlogk) where k is the number of linked lists.
The comparison cost will be reduced to O(logk) for every pop and insertion to priority queue. But finding the node with the smallest value just costs O(1) time.
There are N nodes in the final linked list.
Space complexity :
O(n) Creating a new linked list costs O(n) space.
O(k) The code above present applies in-place method which cost O(1) space. And the priority queue (often implemented with heaps) costs O(k) space (it's far less than N in most situations). 
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp{
    bool operator()(ListNode* l1, ListNode* l2)
    {
        return l1->val > l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(auto l: lists)
        {
            if(l)
                pq.push(l);  // First node of every lists
        }
        
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        while(!pq.empty())
        {
            dummy->next = pq.top();
            pq.pop();
            dummy = dummy->next;
            if(dummy->next)
                pq.push(dummy->next);
        }
        return head->next;
    }
};
