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

//leetcode官方
class Solution {
public:
    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
