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

//leetcode
class Solution {
public:
    int divide(int dividend, int divisor) {
        const int HALF_INT_MIN = -1073741824;//限制了超过 2^32
        int x = dividend, y = divisor;
        //相同为1
        bool sign = (x > 0) ^ (y > 0);
        //统一为负数
        if (x > 0) x = -x;
        if (y > 0) y = -y;

        vector<pair<int, int>> ys;

        //累计被除数
        for (int t1 = y, t2 = -1; t1 >= x; t1 += t1, t2 += t2) {
            ys.emplace_back(t1, t2);
            if (t1 < HALF_INT_MIN)    break;
        }

        int ans = 0;
        for (int i = ys.size() - 1; i >= 0; i--)
            if (x <= ys[i].first) {
            	//累减除数
                x -= ys[i].first;
                //二进制累加商，防止溢出用1ll
                ans += ys[i].second;
            }

        if (!sign) {
            if (ans == INT_MIN)  return INT_MAX;
            ans = -ans;
        }

        return ans;
    }
};