/*
实现 [strStr()](https://baike.baidu.com/item/strstr/811469) 函数。

给你两个字符串 `haystack` 和 `needle` ，请你在 `haystack` 字符串中找出 `needle` 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回 `-1` 。

**说明：**
当 `needle` 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 `needle` 是空字符串时我们应当返回 0 。
**示例 1：**
输入：haystack = "hello", needle = "ll"
输出：2

- `0 <= haystack.length, needle.length <= 5 * 104`
- `haystack` 和 `needle` 仅由小写英文字符组成
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        for (int i = 0; i < n - m + 1; i++) {
            bool ok = true;
            for (int j = 0; j < m; j++)
                if (haystack[i + j] != needle[j]) {
                    ok = false;
                    break;
                }
            if (ok)
                return i;
        }
        return -1;
    }
};