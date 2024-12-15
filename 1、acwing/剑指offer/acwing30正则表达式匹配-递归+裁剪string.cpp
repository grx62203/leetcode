/*
请实现一个函数用来匹配包括'.'和'*'的正则表达式。

模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。

在本题中，匹配是指字符串的所有字符匹配整个模式。

例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配。

数据范围
输入字符串长度 [0,300]。
*/
//

class Solution {
public:
    bool isMatch(string s, string p) 
    {
        if (p.empty())  return s.empty();
        bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
        // *前字符重复>=1次 || *前字符重复0次（不出现）
        if (p.size() >= 2 && p[1] == '*')  
            return (first_match && isMatch(s.substr(1), p)) || isMatch(s, p.substr(2));
        // 不是*，剪去已经匹配成功的头部，继续比较
        else
            return first_match && isMatch(s.substr(1), p.substr(1));    
    }
};