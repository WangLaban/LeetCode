/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
Example:
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *leftDummy = new ListNode(0);
        ListNode *rightDummy = new ListNode(0);
        ListNode *lHead = leftDummy, *rHead = rightDummy;
        ListNode *cur = head;
        while(cur)
        {
            if(cur->val < x)
            {
                lHead->next = cur;
                lHead = lHead->next;
            }
            else
            {
                rHead->next = cur;
                rHead = rHead->next;
            }
            cur = cur->next;
        }
        rHead->next = NULL;
        lHead->next = rightDummy->next;
        return leftDummy->next;
    }
};*/

// Solution2:
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *ins = dummy, *cur = dummy;
        while(cur->next)
        {
            if(cur->next->val >= x)
                cur = cur->next;
            else
            {
                if(cur == ins)
                {
                    cur = cur->next;
                    ins = ins->next;
                }
                else
                {
                    ListNode *move = cur->next;
                    cur->next = move->next;
                    move->next = ins->next;
                    ins->next = move;
                    ins = move;
                }
            }
        }
        return dummy->next;
    }
};
