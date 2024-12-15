/*
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。
*/
//4ms

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());//改成前面低位后面高位
        reverse(b.begin(), b.end());//改成前面低位后面高位

        string c;
        for (int i = 0, t = 0; i < a.size() || i < b.size() || t; i ++ ) {
            if (i < a.size()) t += a[i] - '0';
            if (i < b.size()) t += b[i] - '0';
            c += to_string(t % 2); //保留当前位
            t /= 2;                //得到进位
        }

        reverse(c.begin(), c.end());//改回来，前面高位后面低位
        return c;
    }
};
