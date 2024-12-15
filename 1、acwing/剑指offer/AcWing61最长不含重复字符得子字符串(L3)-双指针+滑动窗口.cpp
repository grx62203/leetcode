/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

假设字符串中只包含从 a 到 z 的字符。

数据范围
输入字符串长度 [0,1000]。

样例
输入："abcabc"

输出：3
*/
class Solution {
public:
    int longestSubstringWithoutDuplication(string s) {
        unordered_map<char,int> hash;
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j ++ )
        {
        	//当j++的时候，发现右窗口字符重复，就移动左窗口，直到右窗口字符不重复
            if ( ++ hash[s[j]] > 1)
            {
                while (i < j)
                {
                    hash[s[i]]--;
                    i ++ ;
                    if (hash[s[j]] == 1) break;
                }
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};

//
class Solution {
public:
    int longestSubstringWithoutDuplication(string s) {
        unordered_map<char,int> hash;
        int res=0;
        for(int i=0,j=0;j<s.size();j++)
        {
            hash[s[j]]++;
            while(hash[s[j]]>1)
            {
                hash[s[i++]]--;
            }

            res=max(res,j-i+1);
        }
        return res;
    }
};

//
class Solution {
public:
    int longestSubstringWithoutDuplication(string s) {
        int st[26] = {0};
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            st[s[i] - 'a']++;
            while (j < i && st[s[i] - 'a'] > 1) 
            {
                st[s[j] - 'a']--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};