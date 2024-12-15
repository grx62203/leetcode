/*
听说最近两斑点的奶牛最受欢迎，约翰立即购进了一批两斑点牛。

不幸的是，时尚潮流往往变化很快，当前最受欢迎的牛变成了一斑点牛。

约翰希望通过给每头奶牛涂色，使得它们身上的两个斑点能够合为一个斑点，让它们能够更加时尚。

牛皮可用一个 N×M 的字符矩阵来表示，如下所示：

................
..XXXX....XXX...
...XXXX....XX...
.XXXX......XXX..
........XXXXX...
.........XXX....
其中，X 表示斑点部分。

如果两个 X 在垂直或水平方向上相邻（对角相邻不算在内），则它们属于同一个斑点，由此看出上图中恰好有两个斑点。

约翰牛群里所有的牛都有两个斑点。

约翰希望通过使用油漆给奶牛尽可能少的区域内涂色，将两个斑点合为一个。

在上面的例子中，他只需要给三个 . 区域内涂色即可（新涂色区域用 ∗ 表示）：

................
..XXXX....XXX...
...XXXX*...XX...
.XXXX..**..XXX..
........XXXXX...
.........XXX....
请帮助约翰确定，为了使两个斑点合为一个，他需要涂色区域的最少数量。

输入格式
第一行包含两个整数 N 和 M。

接下来 N 行，每行包含一个长度为 M 的由 X 和 . 构成的字符串，用来表示描述牛皮图案的字符矩阵。

输出格式
输出需要涂色区域的最少数量。

数据范围
1≤N,M≤50
*/
/*
flood fill算法O(n^2)
数据范围小 50×50
搜索所有联通块，再搜索出第二个联通块（flood-fill算法==DFS简单、可能会爆栈/BFS手写队列与二维坐标但可以求最短路）
然后找两个联通块 的最近距离（），贪心地想，等于曼哈顿距离=横平竖直
最近距离的两个点，之间的曼哈顿距离中没有障碍物，所以枚举两个点的时候可以直接求曼哈顿距离（只是最优解可以，其他距离不可以）
（若最优解的曼哈顿有障碍物，那么便不再是最优解）
真实距离 = 曼哈顿距离 - 1；
就是求使最少的0变成1的连接方法，若搜索到了1，不加，搜索到了0，加1，然后找到联通的最优解
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;//保存图坐标

const int N = 55;

int n, m;
char g[N][N];//定义图
vector<PII> points[2];//保存两个斑点

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//图的上下左右走法

void dfs(int x, int y, vector<PII>& ps)
{
	g[x][y] = '.';
	ps.push_back({x, y});

	for (int i = 0; i < 4; ++i)//图中上下左右走四个方向
	{
		int a = x + dx[i], b = y + dy[i];
		if(a >= 0 && a < n && b >= 0 && b < m && g[a][b] == 'X') dfs(a, b, ps);//如果是 X ，那么再进入修改加入当前集合
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> g[i];//输入图

	for (int i = 0, k = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (g[i][j] == 'X') dfs(i, j, points[k++]);
			//遇到X，直接进入递归找到这个斑点，然后遍历过就修改标记，最后dfs一次得到一个斑点

	int res = 1e8;
	//暴力遍历两个斑点的所有点的曼哈顿距离
	for (auto &a : points[0])
		for (auto &b : points[1])
			res = min(res, abs(a.x-b.x) + abs(a.y-b.y) - 1);//直接求曼哈顿距离 - 1

	cout << res << endl;
	return 0;
}


