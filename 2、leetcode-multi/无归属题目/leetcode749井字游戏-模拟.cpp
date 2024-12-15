/*
给你一个字符串数组 `board` 表示井字游戏的棋盘。当且仅当在井字游戏过程中，棋盘有可能达到 `board` 所显示的状态时，才返回 `true` 。

井字游戏的棋盘是一个 `3 x 3` 数组，由字符 `' '`，`'X'` 和 `'O'` 组成。字符 `' '` 代表一个空位。

以下是井字游戏的规则：

- 玩家轮流将字符放入空位（`' '`）中。
- 玩家 1 总是放字符 `'X'` ，而玩家 2 总是放字符 `'O'` 。
- `'X'` 和 `'O'` 只允许放置在空位中，不允许对已放有字符的位置进行填充。
- 当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。
- 当所有位置非空时，也算为游戏结束。
- 如果游戏结束，玩家不允许再放置字符。
*/
class Solution {
public:
    vector<string> g;    //棋盘的全局变量

    int get(char c)      //计算字符的数量
    {
        int res = 0;
        for (int i = 0; i < 3; i ++ )
            for (int j = 0; j < 3; j ++ )
                if (g[i][j] == c)
                    res ++ ;
        return res;
    }

    bool check(char c)     //判断某 行 或者 列 有没有成功
    {
        for (int i = 0; i < 3; i ++ ) {
            if (g[i][0] == c && g[i][1] == c && g[i][2] == c) return true;//行
            if (g[0][i] == c && g[1][i] == c && g[2][i] == c) return true;//列
        }
        if (g[0][0] == c && g[1][1] == c && g[2][2] == c) return true;//对角线
        if (g[0][2] == c && g[1][1] == c && g[2][0] == c) return true;//反对角线
        return false;
    }

    bool validTicTacToe(vector<string>& board) {
        g = board;
        bool cx = check('X'), co = check('O');
        if (cx && co) return false;                //都成功、非法,第一个总是x
        int sx = get('X'), so = get('O');
        if (cx && sx != so + 1) return false;      //x成功，且x的个数不是o的多一个、非法
        if (co && sx != so) return false;          //o成功，且x的个数不等于o的、非法
        if (sx != so && sx != so + 1) return false;//如果x的个数不等于o的个数，且x的个数不等于o的个数多一个,非法
        return true;
    }
};