/*
将一个骰子投掷 n 次，获得的总点数为 s，s 的可能范围为 n∼6n。

掷出某一点数，可能有多种掷法，例如投掷 2 次，掷出 3 点，共有 [1,2],[2,1] 两种掷法。

请求出投掷 n 次，掷出 n∼6n 点分别有多少种掷法。

数据范围
1≤n≤10
样例1
输入：n=1

输出：[1, 1, 1, 1, 1, 1]

解释：投掷1次，可能出现的点数为1-6，共计6种。每种点数都只有1种掷法。所以输出[1, 1, 1, 1, 1, 1]。
样例2
输入：n=2

输出：[1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1]

解释：投掷2次，可能出现的点数为2-12，共计11种。每种点数可能掷法数目分别为1,2,3,4,5,6,5,4,3,2,1。

      所以输出[1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1]。
*/

class Solution {
public:
    vector<int> numberOfDice(int n) {
        vector<int> res;
        for(int i = n; i <= n * 6; i ++) res.push_back(dfs(n, i));
        return res;
    }

    int dfs(int n, int sum)
    {
        if(sum < 0) return 0;
        if(!n) return !sum;

        int ans = 0;
        for(int i = 1; i <= 6; i ++)
            ans += dfs(n - 1, sum - i);

        return ans;
    }
};

