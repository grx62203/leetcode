/*
给定一个正整数 `n` ，输出外观数列的第 `n` 项。

「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。

你可以将其视作是由递归公式定义的数字字符串序列：

- `countAndSay(1) = "1"`
- `countAndSay(n)` 是对 `countAndSay(n-1)` 的描述，然后转换成另一个数字字符串。

前五项如下：

```
1.     1
2.     11
3.     21
4.     1211
5.     111221
第一项是数字 1 
描述前一项，这个数是 1 即 “ 一 个 1 ”，记作 "11"
描述前一项，这个数是 11 即 “ 二 个 1 ” ，记作 "21"
描述前一项，这个数是 21 即 “ 一 个 2 + 一 个 1 ” ，记作 "1211"
描述前一项，这个数是 1211 即 “ 一 个 1 + 一 个 2 + 二 个 1 ” ，记作 "111221"
```

要 **描述** 一个数字字符串，首先要将字符串分割为 **最小** 数量的组，每个组都由连续的最多 **相同字符** 组成。然后对于每个组，先描述字符的数量，然后描述字符，形成一个描述组。要将描述转换为数字字符串，先将每组中的字符数量用数字替换，再将所有描述组连接起来。

例如，数字字符串 `"3322251"` 的描述如下图：
*/

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 0; i < n - 1; i ++ ) { //每一次 都要把前面 连续相同的分在一组，分组在后面添加 重复次数+重复数
            string t;                       //新的一项要把前面所有的遍历依次
            for (int j = 0; j < s.size();) {//每次都得从s的第一项开始，找一段相同的数
                int k = j + 1;
                while (k < s.size() && s[k] == s[j]) k ++ ;
                t += to_string(k - j) + s[j];//添加   k-j代表相同的个数 + 相同的字符
                j = k;                       //再继续判别，将j更新为相同字符串的下一个
            }
            s = t;
        }
        return s;
    }
};


class Solution {
public:
    string countAndSay(int n) {
        string last = "1"; // 被描述字符串
        for (int i = 2; i <= n; i++){ // 从数字2开始，一直到n
            string cur = ""; // 当前正在构造的新字符串
            int cnt = 0;
            for (int j = 0; j < last.size(); j++){//每次都得从s的第一项开始，找一段相同的数
                cnt++; // 至少有1个字符, 即last[0]
                if (j == last.size() - 1 || last[j] != last[j + 1]){
                    cur += to_string(cnt) + last[j];//添加   k-j代表相同的个数 + 相同的字符
                    cnt = 0;
                }
            }
            last = cur; // 更新 被描述字符串
        }
        return last;
    }
};