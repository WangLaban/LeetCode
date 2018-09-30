/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
Example:
Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
// Solution: Recursion
void generateTreesRe(int start, int end, vector<TreeNode*>& res)
{
    if(start > end)
    {
        res.push_back(NULL);
        return;
    }
    for(int i = start; i <= end; i++)
    {
        vector<TreeNode*> leftSub;
        generateTreesRe(start, i - 1, leftSub);
        vector<TreeNode*> rightSub;
        generateTreesRe(i + 1, end, rightSub);
        for(int j = 0; j < leftSub.size(); j++)
        {
            for(int k = 0; k < rightSub.size(); k++)
            {
                TreeNode *root = new TreeNode(i);
                root->left = leftSub[j];
                root->right = rightSub[k];
                res.push_back(root);
            }
        }
    }
}
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n <= 0)
            return res;
        generateTreesRe(1, n, res);
        return res;
    }
};
