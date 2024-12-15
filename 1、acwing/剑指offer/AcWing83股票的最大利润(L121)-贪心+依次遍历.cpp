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

class Solution {
public:
    int maxDiff(vector<int>& nums) {
        int res = 0;
        for (int i = 0, j = INT_MAX; i < nums.size(); i ++ ) {
        	//存放当前元素与最小的数组元素之差，即答案
            if (j < nums[i])
                res = max(res, nums[i] - j);
            //存放最小的数组元素
            j = min(j, nums[i]);
        }
        return res;
    }
};