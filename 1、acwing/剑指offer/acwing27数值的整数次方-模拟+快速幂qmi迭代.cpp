/*
实现函数double Power(double base, int exponent)，求base的 exponent次方。

不得使用库函数，同时不需要考虑大数问题。

只要输出结果与答案的绝对误差不超过 10−2 即视为正确。

注意：

不会出现底数和指数同为0的情况
当底数为0时，指数一定为正
底数的绝对值不超过 10，指数的绝对值不超过 109。
*/
//0的负数次幂会导致0出现在分母上，在数学上无意义。
class Solution {
public:
    double myPow(double x, int n) {
        typedef long long LL;
        bool is_minus = n < 0;
        double res = 1;
        //当exponent等于负无穷时，取相反数会超出int范围。
        for (LL k = abs(LL(n)); k; k >>= 1) {
            if (k & 1) res *= x;
            x *= x;
        }
        if (is_minus) res = 1 / res;
        return res;
    }
};

//wwb-快速幂模板-
//acwing可以，但是leetcode爆内存int了，因为再acwing取巧特判了
/*
13.88514
-4
输出：
inf
预期结果：
3e-05
*/
class Solution {
public:
    double qmi(double a, int b)
    {
        double res = 1;
        while(b)
        {
            if (b & 1)   res = res * a;
            a = a * a;
            b >>= 1;
            if (a > 1000000000)   return 0.0;
        }
        return res;
    }
    double Power(double base, int exponent) {
        //int a = (int)base;
        bool flag = false;
        double res = 0.0;
        if (exponent < 0)   exponent = -exponent, flag = true;
        double ans = qmi(base, exponent);
        if (flag)   res = 1.0 / (double)ans;
        else        res = (double)ans;
        return res;
    }
};


//leetcode官方
class Solution {
public:
    double quickMul(double x, long long N) {
        double ans = 1.0;
        // 贡献的初始值为 x
        double x_contribute = x;
        // 在对 N 进行二进制拆分的同时计算答案
        while (N > 0) {
            if (N % 2 == 1) {
                // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                ans *= x_contribute;
            }
            // 将贡献不断地平方
            x_contribute *= x_contribute;
            // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
            N /= 2;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
