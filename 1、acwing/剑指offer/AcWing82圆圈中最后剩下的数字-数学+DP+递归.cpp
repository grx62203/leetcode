/*
0,1,…,n−1 这 n 个数字 (n>0) 排成一个圆圈，从数字 0 开始每次从这个圆圈里删除第 m 个数字。

求出这个圆圈里剩下的最后一个数字。

数据范围
1≤n,m≤4000
样例
输入：n=5 , m=3

输出：3
*/

class Solution {
public:
    int lastRemaining(int n, int m){
        if (n == 1) return 0;
        return (lastRemaining(n - 1, m) + m) % n;
    }
};