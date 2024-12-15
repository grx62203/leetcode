/*
给你一根长度为 n 绳子，请把绳子剪成 m 段（m、n 都是整数，2≤n≤58 并且 m≥2）。

每段的绳子的长度记为 k[1]、k[2]、……、k[m]。

k[1]k[2]…k[m] 可能的最大乘积是多少？

例如当绳子的长度是 8 时，我们把它剪成长度分别为 2、3、3 的三段，此时得到最大的乘积 18。
*/
//wwb
//就是最长的时候，段的长度只有x和x+1两种情况
//所以枚举段数i，求出x+1的个数，首先整除i求出一x，然后求余x就是一共x+1可以有多少段
class Solution {
public:
    int maxProductAfterCutting(int length) {
        int ans = 0;
        for (int i = 2; i <= length; i ++)
        {
            int temp = length / i;
            int cnt = length % i;
            int res = 1;
            for (int j = 1; j <= cnt; j ++)       res *= (temp + 1);
            for (int j = cnt + 1; j <= i; j ++)   res *= temp;
            ans = max(ans, res);
        }
        return ans;
    }
};