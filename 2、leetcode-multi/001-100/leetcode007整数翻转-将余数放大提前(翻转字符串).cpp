/*
给你一个 32 位的有符号整数 `x` ，返回将 `x` 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 `[−231, 231 − 1]` ，就返回 0。

**假设环境不允许存储 64 位整数（有符号或无符号）。**

输入：x = 123
输出：321

**提示：**
- `-231 <= x <= 231 - 1`
*/

class Solution {
public:
    //数学中 -5/3=1
    //c++中  -5/3=-2
    int reverse(int x) {
        int res = 0;
        while (x) {
            if (x > 0 && res > (INT_MAX - x % 10) / 10) return 0;
            if (x < 0 && res < (INT_MIN - x % 10) / 10) return 0;
            //ps1
            //if ( y>214748364 || y<-214748364 || (y==-214748364 && x==9) || (y== 214748364 && (x==8||x==9)) ) return 0;
            //ps2
            //如果是longlong ，则直接和INT_MAX比较即可
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};