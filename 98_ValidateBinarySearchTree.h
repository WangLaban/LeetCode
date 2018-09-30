/*
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
Input:
    2
   / \
  1   3
Output: true
Example 2:
    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
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
/*bool isValidBSTRe(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
{
    if(root == NULL)
        return true;
    if((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val))
        return false;
    
    return isValidBSTRe(root->left, minNode, root) && isValidBSTRe(root->right, root, maxNode);
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return root == NULL ? true : isValidBSTRe(root, NULL, NULL);
    }
};*/

// Solution2: Inorder traversal
/*void Inorder(TreeNode* root, vector<int>& vals)
{
    if(root == NULL)
        return;
    Inorder(root->left, vals);
    vals.push_back(root->val);
    Inorder(root->right, vals);
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        vector<int> vals;
        Inorder(root, vals);
        for(int i = 0; i < vals.size() - 1; i++)
        {
            if(vals[i] >= vals[i + 1])
                return false;
        }
        return true;
    }
};*/

// Solution3: Non-recursion with stack
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *cur = root, *pre = NULL;
        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode *temp = st.top();
            st.pop();
            if(pre && pre->val >= temp->val)
                return false;
            pre = temp;
            cur = temp->right;
        }
        return true;
    }
};
