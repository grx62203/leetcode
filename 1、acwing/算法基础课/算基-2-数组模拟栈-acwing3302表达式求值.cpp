/*
给定一个表达式，其中运算符仅包含 +,-,*,/（加 减 乘 整除），可能包含括号，请你求出表达式的最终值。

注意：

数据保证给定的表达式合法。
题目保证符号 - 只作为减号出现，不会作为负号出现，例如，-1+2,(2+2)*(-(1+1)+2) 之类表达式均不会出现。
题目保证表达式中所有数字均为正整数。
题目保证表达式在中间计算过程以及结果中，均不超过 231−1231−1。
题目中的整除是指向 0 取整，也就是说对于大于 0 的结果向下取整，例如 5/3=15/3=1，对于小于 0 的结果向上取整，例如 5/(1−4)=−15/(1−4)=−1。
C++和Java中的整除默认是向零取整；Python中的整除/默认向下取整，因此Python的eval()函数中的整除也是向下取整，在本题中不能直接使用。
输入格式
共一行，为给定表达式。

输出格式
共一行，为表达式的结果。

数据范围
表达式的长度不超过 105
*/

/*
栈-表达式求值
中缀表达式，需要括号判别优先级
数的中序遍历，递归
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int> num;
stack<char> op;

void eval()//用op末尾的运算符操作一下sum末尾的两个数
{
    auto b = num.top(); num.pop();
    auto a = num.top(); num.pop();
    auto c = op.top(); op.pop();
    int x;
    if (c == '+') x = a + b;
    else if (c == '-') x = a - b;
    else if (c == '*') x = a * b;
    else x = a / b;
    num.push(x);
}

int main()
{
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};//操作数的优先级
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i ++ )
    {
        auto c = str[i];
        if (isdigit(c))//处理连续的数字
        {
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j]))
                x = x * 10 + str[j ++ ] - '0';
            i = j - 1;
            num.push(x);
        }
        else if (c == '(') op.push(c);//压入左括号
        else if (c == ')')            //处理左右括号里面的表达式
        {
            while (op.top() != '(') eval();
            op.pop();//弹出左括号
        }
        else
        {
            while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c]) eval();//将比当前运算符优先级高的运算符都运行了
            op.push(c);                                                          //压入当前运算符
        }
    }
    while (op.size()) eval();//遍历一次后，处理了括号、运算符前面更优先的  特殊情况，再从后往前，此时前面优先级都比后面低
    cout << num.top() << endl;
    return 0;
}