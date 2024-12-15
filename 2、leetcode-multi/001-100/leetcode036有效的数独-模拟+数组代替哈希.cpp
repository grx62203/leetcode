/*
请你判断一个 `9x9` 的数独是否有效。只需要 **根据以下规则** ，验证已经填入的数字是否有效即可。

1. 数字 `1-9` 在每一行只能出现一次。
2. 数字 `1-9` 在每一列只能出现一次。
3. 数字 `1-9` 在每一个以粗实线分隔的 `3x3` 宫内只能出现一次。（请参考示例图）

数独部分空格内已填入了数字，空白格用 `'.'` 表示。

**注意：**

- 一个有效的数独（部分已被填充）不一定是可解的。
- 只需要根据以上规则，验证已经填入的数字是否有效即可。

输入：board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
输出：true

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j]` 是一位数字或者 `'.'`
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    	//前面代表某一行、某一列，后面代替这一行、这一列的这个数是否出现过
        int rows[9][9];
        int columns[9][9];
        int subboxes[3][3][9];
        
        memset(rows,0,sizeof(rows));
        memset(columns,0,sizeof(columns));
        memset(subboxes,0,sizeof(subboxes));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int index = c - '0' - 1;
                    rows[i][index]++;
                    columns[j][index]++;
                    subboxes[i / 3][j / 3][index]++;
                    if (rows[i][index] > 1 || columns[j][index] > 1 
                    	|| subboxes[i / 3][j / 3][index] > 1)  return false;       
                }
            }
        }
        return true;
    }
};


class Solution {
public:
    short int v[27][9] = {};
    bool isValidSudoku(vector<vector<char>>& board) {
       
        int x,y = '.' - '1';

        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                x = board[i][j] - '1';
                if(x != y){
                    //先自增，再判断 当前数 在 当前行数组、当前列数组、当前小九宫格数组中出现的次数
                    if(++v[i][x] > 1)                   return 0;
                    if(++v[9 + j][x] > 1)               return 0;
                    if(++v[18 + i/3*3 + j/3][x] > 1)    return 0;
                }
            }
        }
        return 1;
    }
};