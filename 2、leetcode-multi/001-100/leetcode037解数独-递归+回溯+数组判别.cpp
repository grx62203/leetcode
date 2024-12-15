/*
编写一个程序，通过填充空格来解决数独问题。

数独的解法需 **遵循如下规则**：

1. 数字 `1-9` 在每一行只能出现一次。
2. 数字 `1-9` 在每一列只能出现一次。
3. 数字 `1-9` 在每一个以粗实线分隔的 `3x3` 宫内只能出现一次。（请参考示例图）

数独部分空格内已填入了数字，空白格用 `'.'` 表示。

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j]` 是一位数字或者 `'.'`
- 题目数据 **保证** 输入数独仅有一个解
*/


class Solution {
public:

    bool row[9][9], col[9][9], cell[3][3][9];
    //每一行、每一列、每一个小九宫格  的每一位（有重复）  都要有一个数组来记录若干数字的可行性

    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(cell, 0, sizeof cell);

        //遍历，更新数组
        for (int i = 0; i < 9; i ++ )
            for (int j = 0; j < 9; j ++ )
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    row[i][t] = col[j][t] = cell[i / 3][j / 3][t] = true;
                    //ceil  上取整
                }

        dfs(board, 0, 0);
    }

    bool dfs(vector<vector<char>>& board, int x, int y) {
        //按行遍历每一个
        if (y == 9) x ++, y = 0;
        if (x == 9) return true;

        //当前位置有数了，跳到下一个位置
        if (board[x][y] != '.') return dfs(board, x, y + 1);
        
        
        //遍历这个位置可能填的数字
        for (int i = 0; i < 9; i ++ )
        	//第x行，第y列，第m都没有出现过  i 这个数字，将 i 填入 ，调到下一个位置，如果不选择的话恢复现场
            if (!row[x][i] && !col[y][i] && !cell[x / 3][y / 3][i]) 
            {
                board[x][y] = '1' + i;
                row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = true;
                
                //如果下一个不是ture ，恢复一下现场，找当前位置 填入 下一个 数
                if (dfs(board, x, y + 1)) return true; 
                board[x][y] = '.';
                row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = false;
            }

        return false;
    }
};


/*
用3个布尔数组来记录9行、9列、9个小方格中1-9是否使用过
填过数的先初始化到3个布尔数组中
dfs一遍，从左到右，列到边界，行加1
若填过数的，直接返回下一个位置的搜索结果
否则枚举1-9，（数组坐标是0-8）
若当前数字满足条件能填，返回下一个位置的搜索结果
当无法得到true，退出递归时，说明这个数字填了之后，无法得到正确答案
回溯，恢复现场。进循环，尝试下一个数
所有数都尝试过，仍无法返回true，返回false
*/