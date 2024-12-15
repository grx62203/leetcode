/*
给定一个如下图所示的数字三角形，从顶部出发，在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，一直走到底层，要求找出一条路径，使路径上的数字的和最大。

        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
输入格式
第一行包含整数 n，表示数字三角形的层数。

接下来 n 行，每行包含若干整数，其中第 i 行表示数字三角形第 i 层包含的整数。

输出格式
输出一个整数，表示最大的路径数字和。

数据范围
1≤n≤500,
−10000≤三角形中的整数≤10000
输入样例：
*/
/*
0、DP
    状态表示 f[i][j] 
        集合   
            所有 起点走到[i][j]的所有路径
            条件 （数目限制、体积限制）
                只来自左上方 或者 右上方
        属性   
            最大值
            (最小值)
            (数量)
    状态计算
        本质就是集合的划分
        f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);

1、行、反对角线列
*/


#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 1e9;

int n;
int a[N][N];//存储点位值
int f[N][N];//存储起点到某行某反对角列的最大路径和

int main()
{
    scanf("%d", &n);
    //存入点位 值
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= i; j ++ )
            scanf("%d", &a[i][j]);
    //预处理f 为极小值
    for (int i = 0; i <= n; i ++ )
        for (int j = 0; j <= i + 1; j ++ )
            f[i][j] = -INF;
    //处理边界，f0
    f[1][1] = a[1][1];
    //遍历除了边界的其他点 正序，行、反对角列
    for (int i = 2; i <= n; i ++ )
        for (int j = 1; j <= i; j ++ )
            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);
  
    //遍历最下面的一行，找到所有终点位置的 最大路径和  的 max
    int res = -INF;
    for (int i = 1; i <= n; i ++ ) res = max(res, f[n][i]);

    printf("%d\n", res);
    return 0;
}