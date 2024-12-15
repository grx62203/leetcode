/*
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖 一次 该股票可能获得的利润是多少？

例如一只股票在某些时间节点的价格为 [9,11,8,5,7,12,16,14]。

如果我们能在价格为 5 的时候买入并在价格为 16 时卖出，则能收获最大的利润 11。

数据范围
输入数组长度 [0,500]。

样例
输入：[9, 11, 8, 5, 7, 12, 16, 14]

输出：11
*/

//leetcode
// 版本一
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        //持有股票的手里money
        dp[0][0] -= prices[0];
        //不持有股票的手里money
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
        	//持有当前，为当前买入、上一个持有的max
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            //不持有当前，为上一个不持有依旧不持有、上一个持有当前卖出的max
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[len - 1][1];
    }
};


//leetcode
/*从递推公式可以看出，dp[i]只是依赖于dp[i - 1]的状态。
dp[i][0] = max(dp[i - 1][0], -prices[i]);
dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
*/
// 版本二
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.empty()) return 0;
        int len = prices.size();
        vector<vector<int>> dp(2, vector<int>(2)); // 注意这里只开辟了一个2 * 2大小的二维数组
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], prices[i] + dp[(i - 1) % 2][0]);
        }
        return dp[(len - 1) % 2][1];
    }
};




//leetcode
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int min_price = prices[0], n = prices.size();
        vector<int> dp(n, 0);
        for(int i = 1; i < n; i++)
        {
            min_price = min(min_price, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - min_price);
        }
        return dp[n - 1];
    }
};
