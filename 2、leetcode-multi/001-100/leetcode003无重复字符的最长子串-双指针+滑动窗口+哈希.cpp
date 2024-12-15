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
        // 可以找到n^2/2个字符串
        // 尾节点位置为依据分类，依次寻找最长的字符串节选
        unordered_map<char, int> hash;
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j ++ )
        //i在前，j在后，i与j闭区间的字符为动态串
        //先后面的j往后移动，然后判别条件，移动i
        {
            hash[s[j]] ++ ;//每新循环一次，j往后移动一个的同时，将包含j的hash数增加数量1
            while (hash[s[j]] > 1)  //二次循环判别条件是j指向的最后字符出现次数>1
                hash[s[i ++ ]] -- ; //此时就需要将i指向的最前字符hash值减1
                                    //然后将i++，指向后一个字符
                                    //这样子从只有一个字符的串开始，保证最多有一对重复的,发生重复便去除
            res = max(res, j - i + 1);//筛选最长
        }
        return res;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};