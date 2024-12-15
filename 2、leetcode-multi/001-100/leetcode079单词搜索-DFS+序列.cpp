/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

*/
//284ms
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i ++ ) {
            for (int j = 0; j < board[i].size(); j ++ ) {
                //从每一个位置开始dfs搜索这个单词
                if (dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    bool dfs(vector<vector<char>>& board, string& word, int u, int x, int y) {
        //某个字母不符，则这条线不行，层层返回fasle，只有四个方向都false，这个位置才false
        if (board[x][y] != word[u]) return false;
        //如果能走到最后且最后一个字母一样，说明找到了
        if (u == word.size() - 1) return true;

        char t = board[x][y];
        //避免重复被使用
        board[x][y] = '.';
        //dfs四个方向
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            //跳过，不进行dfs
            if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.') continue;
            //层次返回当前方向是否存在，只有有一个方向返回真，这个位置就是真
            if (dfs(board, word, u + 1, a, b)) return true;
        }
        //到这里了，说明这个位置的四个方向都失败了，需要还原现场，以防以后再使用
        board[x][y] = t;
        return false;
    }
};
