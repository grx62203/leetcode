/*
给定两个整数 a 和 b ，求它们的除法的商 a/b ，要求不得使用乘号 '*'、除号 '/' 以及求余符号 '%' 。
注意：

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231, 231−1]。本题中，如果除法结果溢出，则返回 231 − 1
 
示例 1：

输入：a = 15, b = 2
输出：7
解释：15/2 = truncate(7.5) = 7
示例 2：

输入：a = 7, b = -3
输出：-2
解释：7/-3 = truncate(-2.33333..) = -2
示例 3：

输入：a = 0, b = 1
输出：0
示例 4：

输入：a = 1, b = 1
输出：1
 
提示:

-231 <= a, b <= 231 - 1
b != 0
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/xoh6Oh
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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