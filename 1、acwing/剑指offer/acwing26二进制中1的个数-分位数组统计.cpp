/*
输入一个 32 位整数，输出该数二进制表示中 1 的个数。

注意：

负数在计算机中用其绝对值的补码来表示。
数据范围
−100≤ 输入整数 ≤100
*/ 
//时间 lgk
class Solution {
public:
    int NumberOf1(int n) {
        n = (n & 0x55555555) + ((n >>> 1)  & 0x55555555);
        n = (n & 0x33333333) + ((n >>> 2)  & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >>> 4)  & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >>> 8)  & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >>> 16) & 0x0000ffff);
        return n;
    }
};