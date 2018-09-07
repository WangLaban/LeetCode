/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
Note:
Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Solution1: mySolution
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 0 || k == 1 || !head)
            return head;
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        stack<ListNode*> stc;
        
        ListNode *move = head;
        int len = 0;
        while(move)
        {
            len++;
            move = move->next;
        }
        if(k > len)
            return head;
        
        while(len && len / k >= 1)
        {
            for(int i = 0; i < k && head; i++)
            {
                stc.push(head);
                head = head->next;
                len--;
            }
            while(!stc.empty())
            {
                cur->next = stc.top();
                cur = cur->next;
                stc.pop();
            }
        }

        //if(head)  // If len % k == 0, we should assign NULL to cur->next
            cur->next = head;
        return dummy->next;
    }
};
// Solution2: https://github.com/leetcoders/LeetCode/blob/master/ReverseNodesinkGroup.h
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1) return head;
        int reverseTimes = GetLength(head) / k;
        ListNode dummy(0); dummy.next = head;
        ListNode *ins = &dummy, *cur = ins->next;
        while (reverseTimes--) 
        {
            for (int i = 0; i < k - 1; ++i) {
                ListNode *move = cur->next;
                cur->next = move->next;
                move->next = ins->next;  // If modified to move->next = cur, wrong answer will return
                ins->next = move;
            }
            ins = cur;
            cur = ins->next;
        }
        return dummy.next;
    }

    int GetLength(ListNode *head) {
        int length = 0;
        while (head) {
            head = head->next;
            length++;
        }
        return length;
    }
};
