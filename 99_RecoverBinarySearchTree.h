/*
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Example 1:
Input: [1,3,null,null,2]
   1
  /
 3
  \
   2
Output: [3,1,null,null,2]
   3
  /
 1
  \
   2
Example 2:
Input: [3,1,4,null,null,2]
  3
 / \
1   4
   /
  2
Output: [2,1,4,null,null,3]
  2
 / \
1   4
   /
  3
Follow up:
A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
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
// Solution1: Inorder traversal
/*void Inorder(TreeNode* root, vector<TreeNode*>& list, vector<int>& vals)
{
    if(root == NULL)
        return;
    Inorder(root->left, list, vals);
    list.push_back(root);
    vals.push_back(root->val);
    Inorder(root->right, list, vals);
}
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(root == NULL)
            return;
        vector<TreeNode*> list;
        vector<int> vals;
        Inorder(root, list, vals);
        sort(vals.begin(), vals.end());
        for(int i = 0; i < vals.size(); i++)
        {
            list[i]->val = vals[i];
        }
    }
};*/
// Solution2:
/*class Solution {
private:
    TreeNode *pre, *first, *second;
public:
    void recoverTree(TreeNode* root) {
        if(root == NULL)
            return;
        pre = NULL;
        first = NULL;
        second = NULL;
        Inorder(root);
        if(first && second)
            swap(first->val, second->val);
    }
private:
    void Inorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        Inorder(root->left);
        if(!pre)
            pre = root;
        else
        {
            if(pre->val > root->val)
            {
                if(!first)
                    first = pre;
                second = root;
            }
            pre = root;
        }
        Inorder(root->right);
    }
};*/
// Solution3: Morris traversal
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(root == NULL)
            return;
        TreeNode *first = NULL, *second = NULL, *parent = NULL;
        TreeNode *cur = root, *pre;
        while(cur)
        {
            if(cur->left)
            {
                pre = cur->left;
                while(pre->right && pre->right != cur)
                    pre = pre->right;
                if(!pre->right)
                {
                    pre->right = cur;
                    cur = cur->left;
                }
                else
                {
                    pre->right = NULL;
                    if(parent->val > cur->val)
                    {
                        if(!first)
                            first = parent;
                        second = cur;
                    }
                    parent = cur;
                    cur = cur->right;
                }
            }
            else
            {
                if(parent && parent->val > cur->val)
                {
                    if(!first)
                        first = parent;
                    second = cur;
                }
                parent = cur;
                cur = cur->right;
            }
        }
        if(first && second)
            swap(first->val, second->val);
    }
};
