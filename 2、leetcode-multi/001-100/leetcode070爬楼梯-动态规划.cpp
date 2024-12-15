/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
*/
 
class Solution {
public:
    int climbStairs(int n) {
        vector<int>f(n + 1);
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= n; i ++ )
            f[i] = f[i - 1] + f[i - 2];
        return f[n];
    }
};

//优化后的动态规划  每次都累加 前前一次的方案数a、前一次的方案数b 
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        //循环 n-1次
        while ( -- n) {
            int c = a + b;
            a = b, b = c;
        }
        return b;
    }
};