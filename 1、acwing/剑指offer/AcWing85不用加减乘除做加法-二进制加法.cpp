/*
写一个函数，求两个整数之和，要求在函数体内不得使用 ＋、－、×、÷ 四则运算符号。

数据范围
−1000≤num1,num2≤1000
样例
输入：num1 = 1 , num2 = 2

输出：3
*/

//acwing可以运行
/*
二进制加法
两个整数x、y做异或^，得到各位相加不进位的运算结果；      x = a ^ b
两个整数x、y做与&，然后再左移一位，即得到进位的运算结果； y = (a & b) << 1
将上面两个结果相加，即递归重复步骤1,2，直至进位的运算结果为0；a=x、b=y
返回数x
*/
class Solution {
public:
    int add(int num1, int num2){
        while (num2) {
            int sum = num1 ^ num2;
            int carray = (num1 & num2) << 1;
            num1 = sum;
            num2 = carray;
        }
        return num1;
    }
};

//负数左移会报错。所以改成unsigned
class Solution {
public:
    int add(int a, int b){
        while(b) { 
            int s = a ^ b;
            int c =  (unsigned int) (a & b) << 1;
            a = s; 
            b = c; 
        }
        return a;
    }
};