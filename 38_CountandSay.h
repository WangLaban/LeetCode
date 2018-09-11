/*
The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.
Note: Each term of the sequence of integers will be represented as a string.
Example 1:
Input: 1
Output: "1"
Example 2:
Input: 4
Output: "1211"
Input Constraints:
1 <= n <= 30
*/
// Solution1: mySolution
/*class Solution {
public:
    string countAndSay(int n) {
        if(n < 1 || n > 30)
            return "";
        
        vector<string> svec;
        svec.push_back("1");
        svec.push_back("11");
        svec.push_back("21");
        for(int i = 3; i < n; i++)
        {
            string si = "";
            int count = 1;
            for(int j = 0; j < svec[i - 1].size(); j++)
            {
                if(j < svec[i - 1].size() - 1 && svec[i - 1][j] == svec[i - 1][j + 1])
                {
                    count++;
                    continue;
                }
                si += to_string(count) + svec[i - 1][j];
                count = 1;
            }
            svec.push_back(si);
        }
        return svec[n - 1];
    }
};*/

// Solution2: refer to https://github.com/leetcoders/LeetCode/blob/master/CountandSay.h
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; ++i)
        {
            stringstream ss;
            int j = 0, N = res.size();
            while (j < N) {
                int k = j + 1;
                while (k < N && res[k] == res[j])
                    k++;
                ss << (k - j) << res[j];
                j = k;
            }
            ss >> res;
        }
        return res;
    }
};
