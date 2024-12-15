//给定网格的题目
130.被围绕的区域：
	给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
	这题可以用的方法很多，常见的有DFS、BFS和并查集，其中并查集这种数据结构看似不经常用，实际上分析此类题目时候会发挥比较好的作用。
200.岛屿数量：
	给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
	同样也是可以用多种方法的一题。提升：可以思考下如果输入的不是char，而是int的话，该怎么处理。
463.岛屿的周
695.岛屿的最大面积：
	给定一个包含了一些 0 和 1 的非空二维数组grid。一个岛屿是由一些相邻的1(代表土地)构成的组合，这里的「相邻」要求两个1必须在水平或者竖直方向上相邻。你可以假设grid的四个边缘都被0（代表水）包围着。找到给定的二维数组中最大的岛屿面积。
827.最大人工岛
16.19.水域大小：
	你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。
	提升：做完可以与上一题对比下异同点。
1162.地图分析：
	你现在手里有一份大小为NxN的网格grid，上面的每个单元格都用0和1标记好了。其中0代表海洋，1代表陆地，请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的。
994.腐烂的橘子：
	每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。

//拓扑排序的题目：不算BFS，只是思路类似。
207.课程表：
	你这个学期必须选修numCourse门课程，记为0到numCourse-1 。在选修某些课程之前需要一些先修课程。 例如，想要学习课程0，你需要先完成课程1，我们用一个匹配来表示他们：[0,1]。给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
210.课程表 II：
	现在你总共有n门课需要选，记为0到n-1。在选修某些课程之前需要一些先修课程。例如，想要学习课程0，你需要先完成课程1，我们用一个匹配来表示他们: [0,1]。给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
	提升：本地编译环境试试返回所有正确的顺序。（返回值类型改变）
630.课程表 III：
	这里有n门不同的在线课程，他们按从1到n编号。每一门课程有一定的持续上课时间（课程时间）t以及关闭时间第d天。一门课要持续学习t天直到第d天时要完成，你将会从第1天开始。给出n个在线课程用(t, d)对表示。你的任务是找出最多可以修几门课。
	此题可以用拓扑排序，但是可能贪心更方便，题目较难，放在这就是为了系列题好看而已，看不懂的建议直接跳过。

//染色的题目：不算BFS，只是思路类似。
733.图像渲染：
	有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。
08.10.颜色填充：
	题目名称和题目叙述与上一题不太一样，代码可以一模一样。
1042.不邻接植花：
	有 n 个花园，按从 1 到 n 标记。另有数组 paths ，其中 paths[i] = [xi, yi] 描述了花园 xi 到花园 yi 的双向路径。在每个花园中，你打算种下四种花之一。另外，所有花园最多有3条路径可以进入或离开。你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。
	本质上也是个染色问题。

//并查集的题目：很多可以用并查集的题目都可以用dfs和bfs做，因为我并查集学废了，所以指向一个我觉得整理的很棒的链接。
399.除法求值，这篇题解的最后列了很多类似的练习题，学有余力的同学可以做一下哈。






--------------------------994.腐烂的橘子-BFS+多源最短路+最远点最近距离+同时从多源区域边界出发更新步数直到无法扩充边界
--------------------------207.课程表-拓扑排序-------------------------------------------------------
--------------------------210.课程表 II-拓扑排序----------------------------------------------------
--------------------------630.课程表 III-优先队列+贪心-----------------------------------------------
--------------------------733.图像渲染-DFS+flood-fill-----------------------------------------------
--------------------------733.图像渲染-BFS----------------------------------------------------------
--------------------------08.10.颜色填充
--------------------------1042.不邻接植花-邻接表----------------------------------------------------
--------------------------399.除法求值-双向图+unorder_map+Floyd-------------------------------------

// Floyd算法的核心：先枚举中间点，利用中间点来更新左右点的距离
---------------------------------------------------------------------------------------------------
--------------------------130.被围绕的区域-DFS+flood-fill-------------------------------------------
 除了边界o，其他被包围的o都被填充
 //逆向考虑问题，我们先统计出哪些区域不会被攻占，然后将其它区域都变成'X'即可。
	//开一个二维布尔数组，记录哪些区域被遍历过。
	//枚举所有边界上的'O'，从该位置做Flood Fill，即做深度优先遍历，只遍历是'O'的位置，并将所有遍历到的位置都标记成true。
	//将所有未遍历到的位置变成'X'。
 class Solution {
 public:
    int n, m;
    vector<vector<char>> board;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    void solve(vector<vector<char>>& _board) {
        board = _board;
        n = board.size();     //行数
        if (!n) return;
        m = board[0].size();  //列数
        //遍历左边和右边的边界
        for (int i = 0; i < n; i ++ ) {
            if (board[i][0] == 'O') dfs(i, 0);
            if (board[i][m - 1] == 'O') dfs(i, m - 1);
        }
        //遍历上边和下边的边界
        for (int i = 0; i < m; i ++ ) {
            if (board[0][i] == 'O') dfs(0, i);
            if (board[n - 1][i] == 'O') dfs(n - 1, i);
        }
        //将所有未遍历到的位置变成‘X’
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (board[i][j] == '#') board[i][j] = 'O';//边界的0不被填充
                else board[i][j] = 'X';
        _board = board;
    }
    void dfs(int x, int y) {
        board[x][y] = '#';
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && board[a][b] == 'O') 
            	dfs(a, b);
        }
    }
 };
--------------------------130.被围绕的区域-BFS------------------------------------------------------
 除了边界o，其他被包围的o都被填充
 //我们可以使用广度优先搜索实现标记操作。在下面的代码中，我们把标记过的字母 O 修改为字母 A
 class Solution {
 public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) {
            return;
        }
        int m = board[0].size();
        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                que.emplace(i, 0);
                board[i][0] = 'A';
            }
            if (board[i][m - 1] == 'O') {
                que.emplace(i, m - 1);
                board[i][m - 1] = 'A';
            }
        }
        for (int i = 1; i < m - 1; i++) {
            if (board[0][i] == 'O') {
                que.emplace(0, i);
                board[0][i] = 'A';
            }
            if (board[n - 1][i] == 'O') {
                que.emplace(n - 1, i);
                board[n - 1][i] = 'A';
            }
        }
        //先把边界0放入队列，再遍历队列，找到不被包围的0，替换为A
        while (!que.empty()) {
            int x = que.front().first, y = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int mx = x + dx[i], my = y + dy[i];
                if (mx < 0 || my < 0 || mx >= n || my >= m || board[mx][my] != 'O') {
                    continue;
                }
                que.emplace(mx, my);
                board[mx][my] = 'A';
            }
        }
        //将A换回0，将0替换为X
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
 };
--------------------------200.岛屿数量-DFS+flood-fill-----------------------------------------------
 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。，也就是连通块1的数量
 class Solution {
 public:
    vector<vector<char>> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        int cnt = 0;
        for (int i = 0; i < g.size(); i ++ )
            for (int j = 0; j < g[i].size(); j ++ )
                if (g[i][j] == '1') {
                    dfs(i, j);
                    cnt ++ ;               //记录连通块入口数量，
                }
        return cnt;
    }
    void dfs(int x, int y) {
        g[x][y] = 0;                        //遍历到1则化为0，然后每一个连通块就只进去一次
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < g.size() && b >= 0 && b < g[a].size() && g[a][b] == '1')
                dfs(a, b);
        }
    }
 };
--------------------------200.岛屿数量-BFS----------------------------------------------------------
 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。，也就是连通块1的数量
 class Solution {
 public:
    vector<vector<char>> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; // 左-上-右-下
    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        int cnt = 0;
        for (int i = 0; i < g.size(); i ++ )
            for (int j = 0; j < g[0].size(); j ++ )
                if (g[i][j] == '1') {
                    bfs(i, j);
                    cnt ++ ;
                }
        return cnt;
    }
    void bfs(int i, int j) {
        g[i][j] = '2';
        queue<pair<int, int>>q;
        q.push({i, j});
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            int x = t.first, y = t.second;
            for (int k = 0; k < 4; k ++ ) {
                int a = x + dx[k], b = y + dy[k];
                if (a >= 0 && a < g.size() && b >= 0 && b <g[a].size() && g[a][b] == '1') {
                    q.push({a, b});
                    g[a][b] = '2'; // 这里是 '=', 一开始手残打成 "==", leetcode报超时
                }
            }
        }
    }
 };
--------------------------463.岛屿的周-DFS+flood-fill-----------------------------------------------
 给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。没有湖
 class Solution {
    constexpr static int dx[4] = {0, 1, 0, -1};
    constexpr static int dy[4] = {1, 0, -1, 0};
 public:
    //跨越岛界则返回、走到来时路则返回、四个方向都返回则返回
    int dfs(int x, int y, vector<vector<int>> &grid, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0)  return 1;//跨越岛界，周长加1
        if (grid[x][y] == 2)                                        return 0;//走过的地方不累加
        //同在联通的岛屿上，才会往下走，然后dfs此位置的四个方向，累加四个方向返回的周长，用置2来避免dfs返回原路
        grid[x][y] = 2;
        int res = 0;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            res += dfs(tx, ty, grid, n, m);//从某个1开始出发，走到1便置2不累加周长，然后走到0、走出边界累加周长
        }
        return res;
    }
    int islandPerimeter(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ans += dfs(i, j, grid, n, m);
                }
            }
        }
        return ans;
    }
 };
--------------------------463.岛屿的周-BFS----------------------------------------------------------
 给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。没有湖
 class Solution {
 public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        int res = 0;
        for (int i = 0; i < grid.size(); i ++ )
            for (int j = 0; j < grid[i].size(); j ++ )
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k ++ ) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
                            res ++ ;                      //从边界内走向边界外的时候 累加周长
                        else if (grid[x][y] == 0) res ++ ;//从1走向0的时候          累加周长
                    }
                }
        return res;
    }
 };
--------------------------695.岛屿的最大面积-DFS+flood-fill-----------------------------------------
 class Solution {
 public:
    int n, m;
    vector<vector<int>> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int dfs(int x, int y) {
        int res = 1;
        g[x][y] = 0;                         //每次到1就计数 且进入置换成0，标明不再进入
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && g[a][b])
                res += dfs(a, b);            //四个方向计数此方向上的同一岛屿面积
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        g = grid;
        n = g.size(), m = g[0].size();
        int res = 0;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                //每次进入dfs都会去重地计算一个岛屿地面积，且保证遍历其他方格的时候不再进入以前的岛屿
                if (g[i][j])   res = max(res, dfs(i, j));
        return res;
    }
 };
--------------------------695.岛屿的最大面积-DFS+栈-------------------------------------------------
 https://leetcode.cn/problems/max-area-of-island/solution/dao-yu-de-zui-da-mian-ji-by-leetcode-solution/
 用栈来吸收新的岛屿部分，与此同时每次找的都是栈顶，保证了dfs一次深入的特点，把某个方向都搜索完毕才开始下一个方向
--------------------------695.岛屿的最大面积-BFS----------------------------------------------------
 class Solution {
 public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                //遍历每一个方格，以此方格为左上角的岛屿就会被遍历一次清空，每一次遍历都会更新ans
                int cur = 0;
                queue<int> queuei;
                queue<int> queuej;
                queuei.push(i);
                queuej.push(j);
                while (!queuei.empty()) {
                    int cur_i = queuei.front(), cur_j = queuej.front();
                    queuei.pop();
                    queuej.pop();
                    if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1)
                        continue;               //如果没有形成岛屿一部分，跳过
                    ++cur;                      //计数，累计当前岛屿面积
                    grid[cur_i][cur_j] = 0;     //每次到1就计数 且进入置换成0，标明不再进入
                    int di[4] = {0, 0, 1, -1};
                    int dj[4] = {1, -1, 0, 0};
                    for (int index = 0; index != 4; ++index) {
                        int next_i = cur_i + di[index], next_j = cur_j + dj[index];
                        queuei.push(next_i);
                        queuej.push(next_j);
                    }
                }
                ans = max(ans, cur);//每次bfs一次一个格子之后就更新max的ans
            }
        }
        return ans;
    }
 };
--------------------------827.最大人工岛-DFS/BFS----------------------------------------------------
 //首先通过 DFS / BFS 算法求出每个岛的大小，记录下每个坐标所属于的岛的编号。每个岛都记录 size。
 //然后枚举每个 0 格子，将其改变为 1 后，寻找四周不同编号的岛的编号。将这些岛的 size 加起来，然后再加 1 就是合并之后大岛的 size。
 //如果没有 0 格子，则直接返回 size 最大的岛即可（也就是 ans=n∗mans=n∗m）。
 class Solution {
 public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    void dfs(int x, int y, int n, int m, const vector<vector<int>> &grid, int &sz, int idx, vector<vector<int>> &vis) {
        vis[x][y] = idx;
        sz++;                    
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m || grid[tx][ty] == 0 || vis[tx][ty] != -1) continue;
            dfs(tx, ty, n, m, grid, sz, idx, vis);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> sz(n * m, 0);
        vector<vector<int>> vis(n, vector<int>(m, -1));
        int idx = 0, ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1 && vis[i][j] == -1) {
                    dfs(i, j, n, m, grid, sz[idx], idx, vis);
                    ans = max(ans, sz[idx]);  //更新最大岛屿面积
                    idx++;                    //岛屿编号
                }
        for (int x = 0; x < n; x++)
            for (int y = 0; y < m; y++)
                if (grid[x][y] == 0) {                          //遍历每个水格子
                    unordered_set<int> islands;
                    for (int i = 0; i < 4; i++) {
                        int tx = x + dx[i], ty = y + dy[i];
                        if (tx < 0 || tx >= n || ty < 0 || ty >= m || grid[tx][ty] == 0)  continue;
                        islands.insert(vis[tx][ty]);            //如果有相邻岛屿，找到相邻岛屿的编号
                    }
                    int tot = 1;
                    for (int idx : islands)  tot += sz[idx];
                    ans = max(ans, tot);
                }
        return ans;
    }
 };
--------------------------827.最大人工岛-并查集------------------------------------------------------
 class Solution {
 public:
    int n, m;
    vector<int> p, sz;                     //存储着N的父节点、存储这个集合的大小（一般N都是祖宗）
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int find(int x) {                      //返回x的祖宗节点+压缩路径
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    int get(int x, int y) {                //获得x，y坐标到原点的曼哈顿距离也就是每个点的新索引
        return x * m + y;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n * m; i ++ ) p.push_back(i), sz.push_back(1);//更新索引对应
        int res = 1;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (grid[i][j]) {
                    int a = get(i, j);
                    for (int k = 0; k < 4; k ++ ) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y]) {
                            int b = get(x, y);
                            if (find(a) != find(b)) {//如果原来的点a 与 四周某个点b 的祖宗节点不一样
                                sz[find(b)] += sz[find(a)];     //更新 b祖宗所在家族 的点数
                                p[find(a)] = find(b);           //更新 a的祖宗 为 b的祖宗
                            }
                        }
                    }
                    res = max(res, sz[find(a)]);               //更新最大岛屿=最大家族 的点数
                }
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (!grid[i][j]) {                             //遍历每个水格子
                    map<int, int> hash;
                    for (int k = 0; k < 4; k ++ ) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y]) {
                            int a = get(x, y);
                            hash[find(a)] = sz[find(a)];       //如果有相邻家族，找到相邻家族的祖宗，记录这个祖宗所在家族的点数
                        }
                    }
                    int s = 1;
                    for (auto [k, v]: hash) s += v;            //累加联通所有家族的总点数
                    res = max(res, s);                         //更新每个水格子情况的max
                }
        return res;
    }
 };
--------------------------16.19.水域大小------------------------------------------------------------

--------------------------1162.地图分析-BFS+朴素+从水出发求每个水点到所有岛屿的最短距离-----------------
 请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的，并返回该距离。如果网格上只有陆地或者海洋，请返回 -1。
 -从海洋出发找岛屿，每个岛屿都找到最近岛屿
 -从岛屿出发更新海洋的距离，更新海洋的最近距离，
 class Solution {
 public:
  // 定义四个方向的增量，用于计算相邻的坐标
  static constexpr int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
  // 定义最大的矩阵大小
  static constexpr int MAX_N = 100 + 5;
  // 定义坐标结构体，包含x、y坐标和步数
  struct Coordinate {
    int x, y, step;
  };
  int n, m; // 矩阵的行数和列数
  vector<vector<int>> a; // 存储输入的矩阵
  bool vis[MAX_N][MAX_N]; // 标记某个坐标是否已经访问过

  // 辅助函数，用于计算从坐标(x, y)到最近陆地的距离
  int findNearestLand(int x, int y) {
    // 初始化访问数组
    memset(vis, 0, sizeof vis);
    // 创建队列，并将起始坐标加入队列
    queue <Coordinate> q;
    q.push({x, y, 0});
    vis[x][y] = 1;
    // 广度优先搜索
    while (!q.empty()) {
      auto f = q.front(); q.pop();
      // 遍历四个方向
      for (int i = 0; i < 4; ++i) {
        int nx = f.x + dx[i], ny = f.y + dy[i];
        // 检查相邻坐标是否在矩阵范围内
        if (!(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1)) {
          continue;
        }
        // 如果相邻坐标未被访问过，则将其加入队列，并标记为已访问
        if (!vis[nx][ny]) {
          q.push({nx, ny, f.step + 1});
          vis[nx][ny] = 1;
          // 如果相邻坐标是陆地，则返回步数（距离）
          if (a[nx][ny]) {
            return f.step + 1;
          }
        }
      }
    }
    // 如果没有找到陆地，则返回-1
    return -1;
  }

  int maxDistance(vector<vector<int>>& grid) {
    // 获取矩阵的行数和列数
    this->n = grid.size();
    this->m = grid.at(0).size();
    // 将输入的矩阵赋值给成员变量a
    a = grid;
    int ans = -1;
    // 遍历矩阵的每一个坐标点
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        // 如果当前坐标是水域，则计算其到最近陆地的距离，并更新答案
        if (!a[i][j]) {
          ans = max(ans, findNearestLand(i, j));
        }
      }
    }
    // 返回答案
    return ans;
  }
 };
--------------------------1162.地图分析-BFS+多源最短路+最近点最近距离+从岛屿出发更新每个水点的最短距离---
 请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的，并返回该距离。如果网格上只有陆地或者海洋，请返回 -1。
 #define x first
 #define y second
 typedef pair<int, int> PII;
 class Solution {
 public:
    int maxDistance(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size(), INF = 1e8;
        vector<vector<int>> dist(n, vector<int>(m, INF));
        queue<PII> q;
        for (int i = 0; i < n; i ++ ) 
            for (int j = 0; j < m; j ++ )
                if (g[i][j]) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i ++ ) {
                int x = t.x + dx[i], y = t.y + dy[i];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (dist[x][y] >dist[t.x][t.y] + 1) {//一直更新每次遇到的水中点到岛屿的最近曼哈顿距离
                    dist[x][y] = dist[t.x][t.y] + 1; 
                    q.push({x, y});                  //水中点如果有更近的到岛屿曼哈顿距离，就会反复入队
                }
            }
        }
        int res = -1;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (!g[i][j])
                    res = max(res, dist[i][j]);
        if (res == INF) res = -1;
        return res;
    }
 };
--------------------------994.腐烂的橘子-BFS+多源最短路+最远点最近距离+同时从多源区域边界出发更新步数直到无法扩充边界
 值 0 代表空单元格；值 1 代表新鲜橘子；值 2 代表腐烂的橘子。每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
 #define x first
 #define y second
 typedef pair<int, int> PII;
 class Solution {
 public:
    int orangesRotting(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        queue<PII> q;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (g[i][j] == 2)
                    q.push({i, j});
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        int res = 0;
        if (q.size()) res -- ;
        while (q.size()) {
            res ++ ;                   //记录多源区域扩散到最后的步数
            int sz = q.size();         //每一次从所有新的多源区域出发走一步
            while (sz -- ) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 4; i ++ ) {
                    int x = t.x + dx[i], y = t.y + dy[i];
                    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] != 1) continue;
                    g[x][y] = 2;                       //同化
                    q.push({x, y});                    //更新多源区域边界
                }
            }
        }
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (g[i][j] == 1)   return -1;         //验证是否还有臭橘子
        return res;
    }
 };
--------------------------207.课程表-拓扑排序-------------------------------------------------------
 每门课都有前置课程，能否上完所有课
 class Solution {
 public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for (auto& e: edges) {
            int b = e[0], a = e[1];
            g[a].push_back(b);      //添加当前点的 出点，后续点
            d[b] ++ ;               //记录当前点的 入点个数
        }
        queue<int> q;
        for (int i = 0; i < n; i ++ )
            if (d[i] == 0)  q.push(i);        //从入点=0的点，多源出发
        int cnt = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            cnt ++ ;
            for (auto i : g[t])
                if ( -- d[i] == 0) q.push(i); //遍历的出点 入点数更新为0，也添加到多源出发
        }
        return cnt == n;
    }
 };
--------------------------210.课程表 II-拓扑排序----------------------------------------------------
 每门课都有前置课程，输出可能的上课顺序
 class Solution {
 public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for (auto& e: edges) {
            int b = e[0], a = e[1];
            g[a].push_back(b);
            d[b] ++ ;
        }
        queue<int> q;
        for (int i = 0; i < n; i ++ )
            if (d[i] == 0)  q.push(i);
        vector<int> res;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            res.push_back(t);
            for (int i: g[t])
                if ( -- d[i] == 0)   q.push(i);
        }
        if (res.size() < n) res = {};     //没有全部上完课
        return res;
    }
 };
--------------------------630.课程表 III-优先队列+贪心-----------------------------------------------
 每门课都有上课持续和截止日期，输出最多可以修读课程
 class Solution {
 public:
    int scheduleCourse(vector<vector<int>>& courses) {
    	//按照上课截止日期排序
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1];});
        priority_queue<int> heap;
        int tot = 0;
        for (auto& c: courses) {
            tot += c[0];
            heap.push(c[0]);
            if (tot > c[1]) {                 //可以保证删掉一个时间最长的，新的这个一定可以满足，因为新的这个小于等于时间最长的
                tot -= heap.top();
                heap.pop();                   //当有课程超时，删掉时间最长的那门课
            }
        }
        return heap.size();
    }
 };
--------------------------733.图像渲染-DFS+flood-fill-----------------------------------------------
 将指定位置出发的所有相同颜色的面积，替换new颜色
 class Solution {
 public:
    vector<vector<int>> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    void dfs(int x, int y, int color, int newColor) {
        g[x][y] = newColor;
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < g.size() && b >= 0 && b < g[0].size() && g[a][b] == color)
                dfs(a, b, color, newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        g = image;
        int color = g[sr][sc];
        if (color == newColor) return g;
        dfs(sr, sc, color, newColor);
        return g;
    }
 };
--------------------------733.图像渲染-BFS----------------------------------------------------------
 将指定位置出发的所有相同颜色的面积，替换new颜色
 class Solution {
 public:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int currColor = image[sr][sc];
        if (currColor == newColor) return image;
        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> que;
        que.emplace(sr, sc);
        image[sr][sc] = newColor;
        while (!que.empty()) {
            int x = que.front().first, y = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int mx = x + dx[i], my = y + dy[i];
                if (mx >= 0 && mx < n && my >= 0 && my < m && image[mx][my] == currColor) {
                    que.emplace(mx, my);
                    image[mx][my] = newColor;
                }
            }
        }
        return image;
    }
 };
--------------------------08.10.颜色填充 

--------------------------1042.不邻接植花-邻接表----------------------------------------------------
 种花，相邻花园的花不一样，返回任意可行方案
 class Solution {
 public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n);                  /* 建立邻接表 */
        for (auto& p: paths) {
            int a = p[0] - 1, b = p[1] - 1;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> res(n);
        for (int i = 0; i < n; i ++ ) {
            bool st[5] = {};                      /* 每次都得更新相邻颜色占 */
            for (int j: g[i]) st[res[j]] = true;  /* 记录相邻边都占了哪些颜色 */
            for (int j = 1; j <= 4; j ++ )
                if (!st[j]) { res[i] = j; break; }/* 选择没有选过的颜色 */
        }
        return res;
    }
 };
--------------------------399.除法求值-双向图+unorder_map+Floyd-------------------------------------
 class Solution {
 public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_set<string> vers;                             //避免查找的时候重复搜索一个节点
        unordered_map<string, unordered_map<string, double>> d; //建立双向图
        for (int i = 0; i < equations.size(); i ++ ) {
            auto a = equations[i][0], b = equations[i][1];
            auto c = values[i];
            d[a][b] = c, d[b][a] = 1 / c;                       //d表示第一个除以第二个的值
            vers.insert(a), vers.insert(b);
        }
        for (auto k: vers)
            for (auto i: vers)
                for (auto j: vers)
                    if (d[i][k] && d[j][k]) d[i][j] = d[i][k] * d[k][j];
                	// 6/2 ,4/2  所以  6/4 = 6/2 * 2/4
        vector<double> res;
        for (auto q: queries) {
            auto a = q[0], b = q[1];
            if (d[a][b]) res.push_back(d[a][b]);
            else res.push_back(-1);
        }
        return res;
    }
 };
---------------------------------------------------------------------------------------------------


