/*
给定两个整数，被除数 `dividend` 和除数 `divisor`。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 `dividend` 除以除数 `divisor` 得到的商。

整数除法的结果应当截去（`truncate`）其小数部分，例如：`truncate(8.345) = 8` 以及 `truncate(-2.7335) = -2`

输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = truncate(3.33333..) = truncate(3) = 3

- 被除数和除数均为 32 位有符号整数。
- 除数不为 0。
- 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231, 231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
*/

//笔记
//long可以不考虑最特殊的位置   -2^32
//但int需要考虑，所以int处理的时候，将x与y转换为负数，负数域更大

//leetcode
class Solution {
public:
    int divide(int x, int y) {
        typedef long long LL;
        vector<LL> exp;
        bool is_minus = false;
        if (x < 0 && y > 0 || x > 0 && y < 0) is_minus = true;

        LL a = abs((LL)x), b = abs((LL)y);
        //累计被除数，再依次从大到小累减
        for (LL i = b; i <= a; i = i + i) exp.push_back(i);
        
        LL res = 0;
        for (int i = exp.size() - 1; i >= 0; i -- )
            if (a >= exp[i]) {
            	//累减除数
                a -= exp[i];
                //二进制累加商，防止溢出用1ll
                res += 1ll << i; 
            }
        if (is_minus) res = -res;
        if (res > INT_MAX || res < INT_MIN) res = INT_MAX;
        return res;
    }
};