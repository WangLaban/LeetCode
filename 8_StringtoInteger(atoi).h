/*
Implement atoi which converts a string to an integer.
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned.

Note:
Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:
Input: "42"
Output: 42
Example 2:
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:
Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:
Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:
Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
*/
/*
Time complexity : O(n).
Space complexity : O(1). 
*/
//Solution1: mySolution
/*bool isDigit(char c)
{
    if(c >= '0' && c <= '9')
        return true;
    
    return false;
}

class Solution {
public:
    int myAtoi(string str) {
        if(str.length() == 0)
            return 0;
        
        bool negative = false;
        int ret = 0;
        
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == ' ')
                continue;
            
            if(ret != 0 && !isDigit(str[i]))
            {
                if(negative)
                    return -ret;
                return ret;
            }
            
            if(!isDigit(str[i]) && str[i] != '-' && str[i] != '+')
                return 0;
            
            if(str[i] == '-' || str[i] == '+')
            {
                if((i < (str.length()) - 1) && isDigit(str[i + 1]))
                    negative = str[i] == '-';
                else
                    return 0;
            }
            
            if(isDigit(str[i]))
            {
                /*if(!negative && (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && str[i] - '0' > 7)))
                    return INT_MAX;
                else if(negative && (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && str[i] - '0' > 8)))
                    return INT_MIN;
                else
                    ret = ret * 10 + str[i] - '0';*/
                if((ret > INT_MAX / 10) || (ret == INT_MAX / 10 && str[i] - '0' > 7))
                    return negative ? INT_MIN : INT_MAX;
                
                ret = ret * 10 + str[i] - '0';
                
                if((i < (str.length()) - 1) && !isDigit(str[i + 1]))
                    break;
            }
        }
        if(negative)
            return -ret;
        return ret;
    }
};*/
//Solution2: https://github.com/leetcoders/LeetCode/blob/master/StringtoInteger(atoi).h
class Solution {
public:
    int myAtoi(string str) {
        if(str.length() == 0)
            return 0;
        
        bool negative = false;
        int ret = 0;
        
        char * it = &(str[0]);  //str's head address
        
        while(*it == ' ')
            it++;
        if(*it == '+' || *it == '-')
        {
            negative = (*it == '-');
            it++;
        }
        while(isdigit(*it))
        {
            if(ret > INT_MAX / 10 || (ret == INT_MAX / 10 && *it - '0' > 7))
                return negative ? INT_MIN : INT_MAX;
            
            ret = ret * 10 + *it - '0';
            it++;
        }
        return negative ? -ret : ret;
    }
};
