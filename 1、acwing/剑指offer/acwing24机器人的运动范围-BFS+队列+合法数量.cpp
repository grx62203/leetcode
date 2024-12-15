/*
地上有一个 m 行和 n 列的方格，横纵坐标范围分别是 0∼m−1 和 0∼n−1。

一个机器人从坐标 (0,0) 的格子开始移动，每一次只能向左，右，上，下四个方向移动一格。

但是不能进入行坐标和列坐标的数位之和大于 k 的格子。

请问该机器人能够达到多少个格子？

注意:

0<=m<=50
0<=n<=50
0<=k<=100
*/  
//时间：O（nm）
class Solution
{
public:
    int get_sum(pair<int, int> p)
    {
        int s = 0;
        while (p.first)
        {
            s += p.first % 10; //个位
            p.first /= 10;     //十位移到个位上
        }
        while (p.second)
        {
            s += p.second % 10;
            p.second /= 10;
        }
        return s;
    }
    int movingCount(int threshold, int rows, int cols)  //行rows，列cols
    {
        if (!rows || !cols) return 0;                   //为0，则方格不存在
        queue<pair<int, int>> q;
        vector<vector<bool>> st(rows, vector<bool>(cols, false)); //生成一个布尔类型的二维变长数组，并全部初始化为false

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};  //左下右上

        int res = 0;
        q.push({0, 0}); //第一个点入队，从队尾插入
        while (q.size())
        {
            auto t = q.front(); //选择队头的点进行判断
            q.pop();            //当前选择的点出队，队头弹出
            if (st[t.first][t.second] || get_sum(t) > threshold) continue; //如果这个点已经计算过了或者数位之和大于k则continue
            res++;                                                         //进入到这一步的格子符合要求，结果+1
            st[t.first][t.second] = true;
            for (int i = 0; i < 4; i++)
            {
                int x = t.first + dx[i], y = t.second + dy[i];
                //这里可能出现重复入队的情况，但是后面if会筛掉已经判断过的点
                if (x >= 0 && x < rows && y >= 0 && y < cols) q.push({x, y});
            }           
        }
        return res;  
    }
};