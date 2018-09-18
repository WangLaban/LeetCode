/*
Validate if a given string can be interpreted as a decimal number.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:
Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.
*/
class Solution {
public:
    bool isNumber(string s) {
        bool dot = false, digit = false, exp = false;
        int i = 0;
        while(s[i] == ' ')
            i++;
        if(s[i] == '+' || s[i] == '-')
            i++;
        for(; i < s.length() && s[i] != ' '; i++)
        {
            if(isdigit(s[i]))
            {
                digit = true;
            }
            else if(s[i] == '+' || s[i] == '-')
            {
                if((i == s.length() - 1) || s[i + 1] == ' ' || (s[i - 1] != 'e' && s[i - 1] != 'E'))
                    return false;
            }
            else if(s[i] == 'e' || s[i] == 'E')
            {
                if(!digit || exp || (i == s.length() - 1) || s[i + 1] == ' ')
                    return false;
                exp = true;
            }
            else if(s[i] == '.')
            {
                if(dot || exp || (!digit && ((i == s.length() - 1) || s[i + 1] == ' ')))
                    return false;
                dot = true;
            }
            else
            {
                return false;
            }
        }
        while(i < s.length() && s[i] == ' ')
            i++;
        return digit && i == s.length();
    }
};
