/*
一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：

"AAJF" ，将消息分组为 (1 1 10 6)
"KJF" ，将消息分组为 (11 10 6)
注意，消息不能分组为  (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。

给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。

题目数据保证答案肯定是一个 32 位 的整数。

 
*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        s = ' ' + s;//i = 0 时，作为第一个值，不需要判断了
        vector<int> f(n + 1);
        f[0] = 1;
        //f[i]表示的是 前i个数的方案数
        for (int i = 1; i <= n; i ++ ) {
            //后一位 1~9 , 可以独立表示，累加方案数
            if (s[i] >= '1' && s[i] <= '9') f[i] += f[i - 1];
            //后两位 10~26，可以独立表示，累加方案数
            if (i > 1) {
                int t = (s[i - 1] - '0') * 10 + s[i] - '0';
                if (t >= 10 && t <= 26) f[i] += f[i - 2];
            }
        }
        return f[n];
    }
};

