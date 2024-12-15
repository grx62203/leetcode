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

//注释版本

class Solution {
public:
    //从存储信息中获取 board[x][y] 上可以填的候选数字
    bitset<9> getPossibleStatus(int x, int y)
    {
        //逐位取反
        // return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
        return (rows[x] | cols[y] | cells[x / 3][y / 3]).flip();
    }
    //从存储信息中获取当前 board 中候选数字最少的空白格
    vector<int> getNext(vector<vector<char>>& board)
    {
        vector<int> ret;
        int minCnt = 10;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] == '.')
                {
                    auto cur = getPossibleStatus(i, j);
                    //候选数字最少
                    if(cur.count() < minCnt)
                    {
                        ret = {i,j};
                        minCnt = cur.count();
                    }
                }
            }
        }
        return ret;
    }
    //在填入和回溯时更新borad[x][y] 的存储信息（所在的行、列、3*3 宫格 都已经有了哪些数字）。
    //fillFlag = true : 填入; false: 回溯
    void fillNum(int x, int y, int n, bool fillFlag)
    {
        rows[x][n] = (fillFlag) ? 1 : 0;
        cols[y][n] = (fillFlag) ? 1 : 0;
        cells[x/3][y/3][n] = (fillFlag) ? 1: 0;
    }
    
    bool dfs(vector<vector<char>>& board, int cnt)
    {
    	//所有空白格都填完,递归结束
        if (cnt == 0) return true;
        //board 中候选数字最少的空白格 (x,y)
        auto next = getNext(board);
        //next 的候选数字.   相当于二进制，第n个数为 1 代表数字 n+1 是可以填的数
        auto bits = getPossibleStatus(next[0], next[1]);
        for (int n = 0; n < bits.size(); n++)
        {
            if (!bits.test(n)) continue;            //数字 n + 1 不是能填的数字，直接跳过
            //递归
            fillNum(next[0], next[1], n, true);    //填入时更新bitset的存储信息
            board[next[0]][next[1]] = n + '1';     //填入数字字符
            if (dfs(board, cnt - 1)) return true;  //当前填入的是最后一个
            //回溯
            board[next[0]][next[1]] = '.';         //擦除数字字符
            fillNum(next[0], next[1], n, false);   //回溯时更新bitset的存储信息
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) 
    {
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));
        int cnt = 0;//数独 board 中需要填的空白格个数
        //压缩存储每一行、每一列、每一个 3x3 宫格中都出现了哪些数字
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    cnt++;
                    continue;
                };
                int n = board[i][j] - '0';
                rows[i] |= (1 << n-1);
                cols[j] |= (1 << n-1);
                cells[i / 3][j / 3] |= (1 << n-1);
            }
        }
        dfs(board, cnt);
    }

private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;
};
