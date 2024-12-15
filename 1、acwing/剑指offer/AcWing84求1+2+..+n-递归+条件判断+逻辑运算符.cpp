/*
求 1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case 等关键字及条件判断语句 (A?B:C)。

数据范围
1≤n≤1000。

样例
输入：10

输出：55
*/

//leetcode,不满足题目要求
class Solution {
public:
    int sumNums(int n) {
        return n == 0 ? 0 : n + sumNums(n - 1);
    }
};



//leetcode
/*
逻辑运算符 && 为例，对于 A && B 这个表达式，如果 A 表达式返回 False ，那么 A && B 已经确定为 False ，此时不会去执行表达式 B。
同理，对于逻辑运算符 ||， 对于 A || B 这个表达式，如果 A 表达式返回 True ，那么 A || B 已经确定为 \True ，此时不会去执行表达式 B。
*/
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n-1));
        return n;
    }
};
