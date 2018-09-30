/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
Example:
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
// Solution1: Dynamic Programming
// F(i,n)=G(i−1)⋅G(n−i)
Time complexity : the main computation of the algorithm is done at the statement with G[i]. So the time complexity is essentially the number of iterations for the statement, which is 
\sum_{i=2}^{n} i = (2+n)(n-1)/2, to be exact, therefore the time complexity is O(N^2)
Space complexity : The space complexity of the above algorithm is mainly the storage to keep all the intermediate solutions, therefore O(N).
/*class Solution {
public:
    int numTrees(int n) {
        int G[n + 1] = {1, 1};
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                G[i] += G[i - j] * G[j - 1];
            }
        }
        return G[n];
    }
};*/

// Solution2: Catalan number
/*
Time complexity : O(N), as one can see, there is one single loop in the algorithm.
Space complexity : O(1), we use only one variable to store all the intermediate results and the final one.
*/
class Solution {
public:
    int numTrees(int n) {
        long C = 1;  // Note: we should use long here instead of int, otherwise overflow
        for(int i = 0; i < n; i++)
        {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};
