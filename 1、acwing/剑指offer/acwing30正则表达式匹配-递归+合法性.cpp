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
    bool isMatch(string s, string p) {
        if(!p.size())  return !s.size();
        return match(s,p,0,0);
    }
    bool match(string s,string p,int a,int b){
        if(b == p.size())   return a == s.size();
        else if(a == s.size()){
            if(b == p.size() -1 || p[b + 1] != '*')    return false;
            return match(s,p,a,b + 2);
        }
        if(b + 1 == p.size())                  return a + 1 == s.size() && (s[a] == p[b] || p[b] == '.');
        if(p[b+1] != '*'){
            if(s[a] == p[b] || p[b] == '.')    return match(s,p,a+1,b+1);
            return false;
        }
        if(s[a] != p[b] && p[b] != '.')         return match(s,p,a,b+2);
        return match(s,p,a,b+2) || match(s,p,a+1,b+2) || match(s,p,a+1,b);
    }
};
