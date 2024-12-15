/*
给定一个字符串 `s` ，请你找出其中不含有重复字符的 **最长子串** 的长度。

**示例 1:**

```
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

- `0 <= s.length <= 5 * 104`
- `s` 由英文字母、数字、符号和空格组成
```
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2)
            return s.size();
        vector<int>dp(128,-1);
        int res=-1;
        int count=0;
        for(int i=0;i<s.size();++i){
            if(dp[s[i]]!=-1){
               //判断当前的字符串的不重复的长度是否是最大的，并进行保存
                res=max(count,res);
                //获得当前字符之前对应的索引
                int temp=dp[s[i]];
                //将该子字符串中，该索引之前的出现过的字符对应的索引值置为初始的-1
                //j=i-count，是为了获得当前的子字符串的首个字符所在的位置
                for(int j=i-count;j<=temp;++j){
                    dp[s[j]]=-1;
                }
                //更新当前的字符对应的索引
                dp[s[i]]=i;
                //获得新的子字符串的当前的长度
                count=i-temp;
            }
            else{
               //更新当前的需要判断的子字符串中没有重复的字符的个数
                ++count;
                dp[s[i]]=i;
            }
        }
        return max(res,count);
    }
};