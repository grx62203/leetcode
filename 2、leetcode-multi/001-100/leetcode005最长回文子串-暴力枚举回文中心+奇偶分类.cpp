/*
给你一个字符串 `s`，找到 `s` 中最长的回文子串。
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        //遍历回文串的重心
        for (int i = 0; i < s.size(); i ++ )
        {
            //要以奇偶两种形式分别遍历
            //l = left   r = right
            //奇
            int l = i-1, r = i+1;
            //不越界、回文条件
            while( l >=0 &&r < s.size() && s[l] == s[r] )   l --, r ++;
            //和前面的结果比较，r-l-1 是满足回文条件的字符串的长度
            //substr的意思是从第l+1个字符开始（左包含）取r-l-1个字符出来，返回新的字符串
            if(res.size() < r-l-1)   res = s.substr(l+1, r-l-1);
                              
            //偶
            l = i, r = i+1;
            while( l >=0 && r < s.size() && s[l] == s[r] )      l --, r ++;
            if(res.size() < r-l-1)      res = s.substr(l+1, r-l-1);
        }
        return res;
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        int res = 0;
        string str;
        for (int i = 0; i < s.size(); i ++ )//遍历回文中心
        {
            for (int j = 0; i - j >= 0 /*向前走边界*/&& i + j < s.size()/*向后走边界*/; j ++ )  
                if (s[i - j] == s[i + j])
                {
                    if (j * 2 + 1 > res)
                    {
                        res = j * 2 + 1;
                        str = s.substr(i - j, j * 2 + 1);
                    }
                }
                else break;

            for (int j = i, k = i + 1; j >= 0 && k < s.size(); j -- , k ++ )
                if (s[j] == s[k])
                {
                    if (k - j + 1 > res) 
                    {
                        res = k - j + 1;
                        str = s.substr(j, k - j + 1);
                    }
                }
                else break;
        }
        return str;
    }
};