/*
给定一个 n×m 的二维整数数组，用来表示一个迷宫，数组中只包含 0 或 1，其中 0 表示可以走的路，1 表示不可通过的墙壁。

最初，有一个人位于左上角 (1,1) 处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。

请问，该人从左上角移动至右下角 (n,m)处，至少需要移动多少次。

数据保证 (1,1) 处和 (n,m) 处的数字为 0，且一定至少存在一条通路。

输入格式
第一行包含两个整数 n 和 m。

接下来 n 行，每行包含 m 个整数（0 或 1），表示完整的二维数组迷宫。

输出格式
输出一个整数，表示从左上角移动至右下角的最少移动次数。

数据范围
1≤n,m≤100
*/

/*
走迷宫
1、走迷宫求最小距离bfs
    初始化g=0、d=-1，然后添加第一个点
    定义四个方向
    while 队列不空 从小到大遍历距离原点最近的
	    取出队头
            for 取出的距离最小的队头的四个方向中---
                if  如果可以走、没有走过，那么就是第一次到达，更新d[x][y],且加入队列
    直到队列不再添加、队列全部弹出后，说明走到终点了
    	返回d[n-1][m-1] -----这是右下角终点的坐标

也可以用数组或者vector来存储PII，i进行前出后进，也就是手写队列
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N], d[N][N];//g是地图、d是到起点的距离

int bfs()
{
    queue<PII> q;
    //PII q[N*N]

    memset(d, -1, sizeof d);
    d[0][0] = 0;
    q.push({0, 0});
    //q[0] = {0,0};
    //hh = 0, tt =0

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (q.size())
    //while(hh<=tt)
    {
        auto t = q.front();         //取出队头且弹出
        q.pop();
        //auto t = q[hh++]

        for (int i = 0; i < 4; i ++ )//遍历当前位置的四个方向
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;//更新距离
                q.push({x, y});//添加队尾
                //q[++tt] = {x,y}; 
            }
        }
    }

    return d[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}