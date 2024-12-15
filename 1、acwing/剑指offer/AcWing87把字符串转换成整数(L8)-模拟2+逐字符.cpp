/*
请你写一个函数 StrToInt，实现把字符串转换成整数这个功能。

当然，不能使用 atoi 或者其他类似的库函数。

数据范围
输入字符串长度 [0,20]。

样例
输入："123"

输出：123
注意:

你的函数应满足下列条件：

忽略所有行首空格，找到第一个非空格字符，可以是 ‘+/−’ 表示是正数或者负数，紧随其后找到最长的一串连续数字，将其解析成一个整数；
整数后可能有任意非数字字符，请将其忽略；
如果整数长度为 0，则返回 0；
如果整数大于 INT_MAX(231−1)，请返回 INT_MAX；如果整数小于INT_MIN(−231) ，请返回 INT_MIN；
*/

//acwing
class Solution {
public:
    int myAtoi(string str) {
        int res = 0;                        //将int换成longlong 完全可以
        int k = 0;
        while (k < str.size() && str[k] == ' ') k ++ ;
        if (k == str.size()) return 0;

        int minus = 1;
        if (str[k] == '-') minus = -1, k ++ ;
        if (str[k] == '+')
            if (minus == -1) return 0;          //此时  -+跟着出现了
            else k ++ ;
        
        while (k < str.size() && str[k] >= '0' && str[k] <= '9') {
            int x = str[k] - '0';  
            if (minus > 0 && res > (INT_MAX - x) / 10) return INT_MAX;
            if (minus < 0 && -res < (INT_MIN + x) / 10) return INT_MIN;
            //补全忽略的情形
            if (-res * 10 - x == INT_MIN) return INT_MIN;
            res = res * 10 + x;
            k ++ ;
        }

        res *= minus;
        return res;
    }
};