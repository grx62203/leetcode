/*
输入一个非负整数 S，打印出所有和为 S 的连续正数序列（至少含有两个数）。

例如输入 15，由于 1+2+3+4+5=4+5+6=7+8=15，所以结果打印出 3 个连续序列 1∼5、4∼6 和 7∼8。

数据范围
0≤S≤1000
样例
输入：15

输出：[[1,2,3,4,5],[4,5,6],[7,8]]
*/

class Solution {
public:
    vector<vector<int> > findContinuousSequence(int sum) {
        vector<vector<int>> res;
        for (int i = 1, j = 1, s = 1; i <= sum; i ++ )
        {
        	//s从i-j的已经在s了，累加j看有没有机会，直到s>=sum,此时累加的是[i,j]
            while (s < sum) j ++, s += j;
            if (s == sum && j > i)
            {
                vector<int> line;
                for (int k = i; k <= j; k ++ ) line.push_back(k);
                res.push_back(line);
            }
            //每次只减去序列前面一个，后面的可以省略相加到s了
            s -= i;
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int> > findContinuousSequence(int sum) {
        vector<vector<int>> res;
        vector<int> path;
        for(int i = 1, j = 2; j < sum && i < j; j) {
            int ans = (i + j) * (j - i + 1) / 2;
            if ( ans == sum){//如果相同就加入。
                int k = i;
                while(k <= j)   path.push_back(k++);
                res.push_back(path);
                path.clear();
                i ++, j ++;//两个指针同时往后移。
            }
            else if ( ans < sum) {//如果比较小，j就往后移动。
                j ++;
            }
            else 
                i ++;//否则i往后移动
        }
        return res;

    }
};