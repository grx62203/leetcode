/*
输入一个 n 行 m 列的整数矩阵，再输入 q 个询问，每个询问包含四个整数 x1,y1,x2,y2，表示一个子矩阵的左上角坐标和右下角坐标。

对于每个询问输出子矩阵中所有数的和。

输入格式
第一行包含三个整数 n，m，q

接下来 n 行，每行包含 m 个整数，表示整数矩阵。

接下来 q 行，每行包含四个整数 x1,y1,x2,y2，表示一组询问。

输出格式
共 q 行，每行输出一个询问的结果。

数据范围
1≤n,m≤1000
1≤q≤200000
1≤x1≤x2≤n
1≤y1≤y2≤m
−1000≤矩阵内元素的值≤1000
*/
#include <iostream>
using namespace std;

const int N = 1010;

int n, m, q;
int s[N][N];

int main()
{
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            //输入 网格点坐标，默认已有左上角 原点
            scanf("%d", &s[i][j]);

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            //求每个以左上角坐标为固定角的矩形的面积，也就是前缀和
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];//求前缀和
            

    while (q -- )//做q个询问
    {
        int x1, y1, x2, y2;//一个新的矩形左上、右下角坐标
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        //用公式求出一个新的矩形面积，前缀和减去 2 个矩形，再加上一个重叠的矩形
        printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);//算子矩阵
        
    }

    return 0;
}