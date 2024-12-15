/*
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
*/
/*
DFS-n皇后Ⅰ
1、遍历行，判断所在列、所在主对角线、副对角线是否被标记
2、全局变量	
	阶数n、路径path、答案ans、bool数组-列+主对角线+副对角线
3、u = n的时候，完成一个方案
4、位运算方法
x & (−x) 可以获得 x 的二进制表示中的最低位的 1 的位置；
x & (x−1) 可以 将 x 的二进制表示中的最低位的 1 置成 0。
具体做法是，每次获得可以放置皇后的位置中的最低位，并将该位的值置成 0，尝试在该位置放置皇后。这样即可遍历每个可以放置皇后的位置。
*/
//4ms
class Solution {
public:
    int n;
    vector<string> path;
    vector<vector<string>> ans;
    vector<bool> col, dg, udg;

    vector<vector<string>> solveNQueens(int n1) {
        n = n1;
        col = vector<bool>(n);
        dg = udg = vector<bool>(n*2);
        path = vector<string>(n, string(n, '.'));

        dfs(0);
        return ans;
    }

    void dfs(int u){
        if(u == n){
            ans.push_back(path);
            return;
        }
        //遍历当前行所有位置，如果有空，填进去算一条路，跳到下一行选择
        for(int i = 0; i < n; i ++){
            if(!col[i] && !dg[u-i+n] && !udg[u+i]){
                path[u][i] = 'Q';
                col[i] = dg[u-i+n] = udg[u+i] = true;
                dfs(u+1);
                path[u][i] = '.';
                col[i] = dg[u-i+n] = udg[u+i] = false;
            }
        }
    }
};