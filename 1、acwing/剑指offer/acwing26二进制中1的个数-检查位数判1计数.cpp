/*
输入一个 32 位整数，输出该数二进制表示中 1 的个数。

注意：

负数在计算机中用其绝对值的补码来表示。
数据范围
−100≤ 输入整数 ≤100
*/ 

class Solution {
public:
	int NumberOf1t(int n) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans += ((n >> i) & 1);
        }
        return ans;
    }
};