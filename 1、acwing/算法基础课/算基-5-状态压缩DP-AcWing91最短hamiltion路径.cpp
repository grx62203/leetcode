/*
给定一张 n 个点的带权无向图，点从 0∼n−1 标号，求起点 0 到终点 n−1 的最短 Hamilton 路径。

Hamilton 路径的定义是从 0 到 n−1 不重不漏地经过每个点恰好一次。

输入格式
第一行输入整数 n。

接下来 n 行每行 n 个整数，其中第 i 行第 j 个整数表示点 i 到 j 的距离（记为 a[i,j]）。

对于任意的 x,y,z，数据保证 a[x,x]=0，a[x,y]=a[y,x] 并且 a[x,y]+a[y,z]≥a[x,z]。

输出格式
输出一个整数，表示最短 Hamilton 路径的长度。

数据范围
1≤n≤20
0≤a[i,j]≤107
*/
/*
0、DP
    状态表示 f[i][j] 
        集合   
            从 0 走到 j 中间走过的 所有点保存在二进制 i 的 最短路径
        属性   
            最小值
    状态计算
        本质就是集合的划分
        枚举 倒数第二个点（k = 0、1、2、、、、、n-1）
            0------>k->j;
            目标是 使  0------>k 最短，也就是 使 i - {j点} 当前路径最短
            f[i-{j}][k] + a(k)(j)

1、n！*n,暴力计算时间复杂度
2、状态压缩dp---------用一个整数表示一个状态，状态也就是二进制
3、最短Hamilton路径
    初始化任意两点权重
    memset 所有dp状态初始化为正无穷
    f[1][0] = 0 起点为 0 ， 经过了 00000001 表示的第一个点 的最短路径 = 0
    for 枚举 所有状态，此时状态为 1 的位 从右开始 表示经过的哪些点
        for 枚举 每个状态 下的每个终点可能性
            if 如果 状态 i 包含 j点，终点才合法
                for 枚举 倒数第二个点，如果状态 i 包含 k 点，前一个点才合法（当k=j的时候，f[i-(i<<j)][j]为正无穷，不影响结果）
                    f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]) 
                    ---包含j的i--0到达 j 的最段路径 = min（若干（不包含j的i--0到达每一个可能的前一个点k的最短距离 + k到j的固定距离））
    cout << f[(1 << n) - 1][n - 1]---(1 << n) - 1 代表 n 个 1的二进制表示，表示所有n个点都经过了，n-1 代表达到  点n-1
*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20, M = 1 << N;//20、2^20

int n;
int w[N][N]; //两点权重（距离）
int f[M][N]; //dp状态

int main()
{
    //初始化任意两点权重
    cin >> n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            cin >> w[i][j];
    //所有dp状态初始化为正无穷
    memset(f, 0x3f, sizeof f);
    //起点为 0 ， 经过了 00000001 表示的第一个点
    f[1][0] = 0;
    //二进制 i 表示经过的点、j表示当前到达的点 的最短路径 = 0
    //枚举 所有状态，此时状态为 1 的位 从右开始 表示经过的哪些点
    for (int i = 0; i < 1 << n; i ++ )
        //枚举 每个状态 下的每个终点可能性
        for (int j = 0; j < n; j ++ )
            //如果 状态 i 包含 j点，终点才合法
            if (i >> j & 1)//也就是i的从右开始第 j 位是 1
                //枚举 倒数第二个点，如果状态 i 包含 k 点，前一个点才合法
                for (int k = 0; k < n; k ++ )
                    //if( i-(1<<j) >> k & 1 )//不包含j点二进制i的从右开始第 k 位是 1，意思是k！=j
                    if (i >> k & 1)          //包含j点的二进制i的从右开始第 k 位是 1（当k=j的时候，f[i-(i<<j)][j]为正无穷，不影响结果）
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
                        //包含j的i--0到达 j 的最段路径 = min（若干（不包含j的i--0到达每一个可能的前一个点k的最短距离 + k到j的固定距离））
                        // i - (1 << j) 表示 二进制 i 的从右第 j 位 化 1 为 0
                        //      1 << 3  = 1000
    //(1 << n) - 1 代表 n 个 1的二进制表示，表示所有n个点都经过了
    //n-1          代表达到  点n-1
    cout << f[(1 << n) - 1][n - 1];

    return 0;
}
