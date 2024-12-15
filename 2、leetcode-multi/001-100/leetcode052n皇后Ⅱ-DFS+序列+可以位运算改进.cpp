/*
n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
*/
//4ms
class Solution {
public:
    int n,m;
    vector<string> path;
    vector<bool> col, dg, udg;
    
    int totalNQueens(int n1) {
        n = n1;
        col = vector<bool>(n);
        dg = udg = vector<bool>(n*2);
        path = vector<string>(n, string(n, '.'));

        dfs(0);
        return m;
    }

    void dfs(int u){
        if(u == n){
            m ++;
            return;
        }
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