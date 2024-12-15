/*
写一个函数，求两个整数之和，要求在函数体内不得使用 ＋、－、×、÷ 四则运算符号。

数据范围
−1000≤num1,num2≤1000
样例
输入：num1 = 1 , num2 = 2

输出：3
*/


//
class Solution {
public:
    int add(int num1, int num2){
        int res = 0;
        int Cin = 0;
        int tmp = 1;
        for(int i = 0;i<32;i++){
            int a = num1 & tmp;//取得num1和num2的第i位的值
            int b = num2 & tmp;
            int S = (a^b)^Cin;//异或得到第i位的输出值
            int Cout = (a&b)|(a&Cin)|(b&Cin);//与操作得到进位
            Cin = Cout << 1;//传递到下一位的进位输入
            tmp <<= 1;
            res += S;//将第i位的输出值S加到res中
        }
        return res;
    }
};


//
class Solution {
public:
    // 全加器的实现，负数用补码表示，也适用
    int add(int num1, int num2){
        if(num1 == 0) return num2;
        if(num2 == 0) return num1;
        int sum = 0;
        int bitMask = 1;
        int bit1 = 0;
        int bit2 = 0;
        int carry = 0;
        for(int i = 0; i < 32; ++i){
            bit1 = num1 & bitMask;
            bit2 = num2 & bitMask;
            sum |= (bit1 ^ bit2) ^ carry;
            bitMask = bitMask << 1;
            carry = (bit1&bit2)|(bit1&carry)|(bit2&carry);
            carry = carry << 1;
        }
        return sum;
    }
};