/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
Example:
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/
void restoreIpAddressesRe(string &s, int start, int deep, string &ip, vector<string>& res)
{
    if(deep == 4 && start == s.length())
        res.push_back(ip);
    if(deep == 4)
        return;
    int num = 0, len = ip.length();
    if(len != 0)
        ip.push_back('.');
    for(int i = start; i < s.length(); i++)
    {
        num = num * 10 + s[i] - '0';
        if(num > 255)
            break;
        ip.push_back(s[i]);
        restoreIpAddressesRe(s, i + 1, deep + 1, ip, res);
        if(num == 0)
            break;
    }
    ip.resize(len);
}
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        restoreIpAddressesRe(s, 0, 0, ip, res);
        return res;
    }
};
