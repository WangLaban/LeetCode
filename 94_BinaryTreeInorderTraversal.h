/*
Given a binary tree, return the inorder traversal of its nodes' values.
Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3
Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
Time complexity : O(n). The time complexity is O(n) because the recursive function is T(n)=2⋅T(n/2)+1.
Space complexity : The worst case space required is O(n), and in the average case it's O(log(n)) where n is number of nodes. 
*/
/*void inorderTraversalRe(TreeNode* root, vector<int>& res)
{
    if(!root)
        return;
    inorderTraversalRe(root->left, res);
    res.push_back(root->val);
    inorderTraversalRe(root->right, res);
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversalRe(root, res);
        return res;
    }
};*/

// Solution2: Iterating method using Stack
/*
Time complexity : O(n).
Space complexity : O(n). 
*/
/*class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            res.push_back(cur->val);
            st.pop();
            cur = cur->right;
        }
        return res;
    }
};*/

// Solution3: Morris Traversal
/*
Time complexity : O(n). To prove that the time complexity is O(n), the biggest problem lies in finding the 
time complexity of finding the predecessor nodes of all the nodes in the binary tree. Intuitively, the 
complexity is O(nlogn), because to find the predecessor node for a single node related to the height of 
the tree. But in fact, finding the predecessor nodes for all nodes only needs O(n) time. Because a binary 
Tree with nn nodes has n−1 edges, the whole processing for each edges up to 2 times, one is to locate a 
node, and the other is to find the predecessor node. So the complexity is O(n).
Space complexity : O(n). Arraylist of size n is used.
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur = root;
        TreeNode *pre;
        while(cur)
        {
            if(cur->left == NULL)
            {
                res.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                pre = cur->left;
                while(pre->right)
                    pre = pre->right;
                pre->right = cur;
                TreeNode *temp = cur;
                cur = cur->left;
                temp->left = NULL;
            }
        }
        return res;
    }
};
