/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。

路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。

如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。

注意：

输入的路径不为空；
所有出现的字符均为大写英文字母；
数据范围
矩阵中元素的总个数 [0,900]。
路径字符串的总长度 [0,900]。
*/
//wwb
class Solution {
public:
    bool hasPath(vector<vector<char>>& matrix, string &str) {
        if (matrix.size() == 0)  return false;
        for (int i = 0; i < matrix.size(); i ++)
        {
            for (int j = 0; j < matrix[i].size(); j ++)
            {
                if (dfs(matrix, str, 0, i, j))   return true;
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>> &s, string &str, int u, int x, int y)
    {
        if (x < 0 || x >= s.size() || y < 0 || y > s[0].size())  return false;//判别边界，也可以放在dfs前
        if (str[u] != s[x][y])   return false;
        if (u + 1 == str.size())  return true;

        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

        char temp = s[x][y];
        s[x][y] = '*';

        for (int i = 0; i < 4; i ++)
        {
        	//也可以先判别边界再进入dfs
            if(dfs(s, str, u + 1, x + dx[i], y + dy[i]))  return true;
        }

        s[x][y] = temp;
        return false;
    }
};