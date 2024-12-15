/*
求 1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case 等关键字及条件判断语句 (A?B:C)。

数据范围
1≤n≤1000。

样例
输入：10

输出：55
*/


class Solution {
public:
    int getSum(int n) {
        char a[n][n+1];
        return sizeof(a)>>1;
    }
};



//leetcode
class Solution {
public:
    int sumNums(int n) {
        bool a[n][n+1];
        return sizeof(a)>>1;
    }
};
//ans=1+2+3+...+n
//   =(1+n)*n/2
//   =sizeof(bool a[n][n+1])/2
//   =sizeof(a)>>1



//leetcode
class Solution {
public:
    int sumNums(int n) {
        return sizeof(bool[n][n+1])>>1;
    }
};
