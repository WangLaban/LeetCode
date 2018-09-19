/*
Given an absolute path for a file (Unix-style), simplify it. 
For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
path = "/a/../../b/../c//.//", => "/c"
path = "/a//b////c/d//././/..", => "/a/b/c"
In a UNIX-style file system, a period ('.') refers to the current directory, so it can be ignored in a simplified path. Additionally, a double period ("..") moves up a directory, so it cancels out whatever the last directory was. For more information, look here: https://en.wikipedia.org/wiki/Path_(computing)#Unix_style
Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
path = "/...", => "/..."
path = "/..", => "/"
*/
// Solution: Add an additional '/' at the end of 'path' for simply detecting the end
class Solution {
public:
    string simplifyPath(string path) {
        string res;
        path += "/";
        size_t pos = path.find_first_of("/"), last = 0;
        while(pos != string::npos)
        {
            string s = path.substr(last, pos - last);
            if(s == "..")
            {
                if(!res.empty())
                    res.resize(res.find_last_of("/"));
            }
            else if(!s.empty() && s != ".")
            {
                res += "/";
                res += s;
            }
            last = pos + 1;
            pos = path.find_first_of("/", last);
        }
        return res.empty() ? "/" : res;
    }
};
