/*
输入一个 32 位整数，输出该数二进制表示中 1 的个数。

注意：

负数在计算机中用其绝对值的补码来表示。
数据范围
−100≤ 输入整数 ≤100
*/ 
/*
详细见 csapp，这里大概说一下
大部分语言实现的类型转换，底层二进制是不变的，只是改变了二进制位的解释
无符号类型的右移是逻辑右移，即高位补 0
*/
//时间 k
class Solution {
public:
    int NumberOf1(int n) {
        int res = 0;
        unsigned int un = n; 
        while (un) res += un & 1, un >>= 1;
        return res;
    }
};