/*
Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
Example 1:
Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:
Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:
Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Solution1: Recursion
/*
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(p && !q || !p && q || p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};*/

// Solution2: DLR -- Preorder traversal
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode *> s1, s2;
        if(p)
            s1.push(p);
        if(q)
            s2.push(q);
        while(!s1.empty() && !s2.empty())
        {
            TreeNode *t1 = s1.top();
            TreeNode *t2 = s2.top();
            if(t1->val != t2->val)
                return false;
            s1.pop(); s2.pop();
            if(t1->left)
                s1.push(t1->left);
            if(t2->left)
                s2.push(t2->left);
            if(s1.size() != s2.size())
                return false;
            if(t1->right)
                s1.push(t1->right);
            if(t2->right)
                s2.push(t2->right);
            if(s1.size() != s2.size())
                return false;
        }
        return s1.size() == s2.size();
    }
};
