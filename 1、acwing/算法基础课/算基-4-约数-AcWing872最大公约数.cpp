/*
最大公约数

给定 n 对正整数 ai,bi，请你求出每对数的最大公约数。
输入格式
第一行包含整数 n。
接下来 n 行，每行包含一个整数对 ai,bi。
输出格式
输出共 n 行，每行输出一个整数对的最大公约数。
*/
#include <iostream>
#include <algorithm>

using namespace std;

//欧几里得/辗转相除法
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;//推理过程在md笔记中
}


int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }

    return 0;
}