/*
给定 n 组询问，每组询问给定两个整数 a，b，请你输出 Cba mod (109+7) 的值。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一组 a 和 b。

输出格式
共 n 行，每行输出一个询问的解。

数据范围
1≤n≤10000,
1≤b≤a≤2000
*/
//1、a、b较小的时候用这个公式， C ab = C a-1 b + C a-1 b-1

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2010, mod = 1e9 + 7;


int c[N][N];//预处理组合数数组


void init()
{
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j <= i; j ++ )
            if (!j) c[i][j] = 1;                                 //i里面选0个苹果只有一种方案
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;//i里面选j个苹果有两种情况
}


int main()
{
    int n;

    init();

    scanf("%d", &n);

    while (n -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);

        printf("%d\n", c[a][b]);
    }

    return 0;
}