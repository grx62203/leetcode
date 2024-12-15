 /*
输入一个 非空 整型数组，数组里的数可能为正，也可能为负。

数组中一个或连续的多个整数组成一个子数组。

求所有子数组的和的最大值。

要求时间复杂度为 O(n)。

数据范围
数组长度 [1,1000]。
数组内元素取值范围 [−200,200]。

样例
输入：[1, -2, 3, 10, -4, 7, 2, -5]

输出：18
*/
//当累加和小于0，则清空重新累加
//每次累加后比较ans与累加和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, s = 0;
        for (auto x : nums)
        {
            if (s < 0) s = 0;
            s += x;
            res = max(res, s);
        }
        return res;
    }
};