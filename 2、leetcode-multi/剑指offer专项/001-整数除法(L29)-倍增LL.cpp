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