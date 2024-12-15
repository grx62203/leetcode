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

//不能直接换为int 要注意int比long long 小，
/*
执行出错信息：
Line 16: Char 23: runtime error: signed integer overflow: 912834723 * 10 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:25:23
最后执行的输入：
"-91283472332"
*/

//acwing
class Solution {
public:
    int strToInt(string str) {
    	//1、去除空格
        int k = 0;
        while (k < str.size() && str[k] == ' ') k ++ ;
        long long res = 0;
        //2、默认正数，找正负号
        int minus = 1;
        if (k < str.size())
        {
            if (str[k] == '-') minus = -1, k ++ ;
            else if (str[k] == '+') k ++ ;
        }
        //3、累加数字
        while (k < str.size() && str[k] >= '0' && str[k] <= '9')
        {
            res = res * 10 + str[k] - '0';
            if (res > 1e11) break;
            k ++ ;
        }
        //4、求得实际值
        res *= minus;
        if (res > INT_MAX) res = INT_MAX;
        if (res < INT_MIN) res = INT_MIN;

        return res;
    }
};
