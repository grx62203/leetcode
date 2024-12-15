/*
给定一个长度为 N 的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出 −1。

输入格式
第一行包含整数 N，表示数列长度。

第二行包含 N 个整数，表示整数数列。

输出格式
共一行，包含 N 个整数，其中第 i 个数表示第 i 个数的左边第一个比它小的数，如果不存在则输出 −1。

数据范围
1≤N≤105
1≤数列中元素≤109
*/
#include <iostream>

using namespace std;

const int N = 100010;

int stk[N], tt;

int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        int x;
        scanf("%d", &x);
        while (tt && stk[tt] >= x) tt -- ;//如果栈不空、栈顶元素大于当前x，则弹出
        if (!tt) printf("-1 ");
        else printf("%d ", stk[tt]);//得到一个单调的栈，存储的是 从前到后有单调，输出上一个元素，所以在前
        stk[ ++ tt] = x;//当栈顶元素比当前元素小的时候，压入 x ，可能会霸占删掉某次弹出元素所在的数组位置
    }

    return 0;
}