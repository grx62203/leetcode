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
/********************************************************************************************/
/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组 是数组中的一个连续部分。
*/
/*
dp代表包含当前位置的左串的最大前缀和 = max（包括当前值的前缀和，当前值）
dp[i] = max(dp[i-1] + nums[i], nums[i]);
ans = max(ans, dp);
*/
//80ms
//leetcode
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int ans = INT_MIN;
    	int n = int(nums.size());
    	if (!n) return 0;
    	int dp(nums[0]);
    	ans = dp;
    	for (int i = 1; i < n; ++i)
    	{
    		dp = max(dp+nums[i] , nums[i]);
    		ans = max(ans, dp);
    	}
    	return ans;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        for (int i = 0, last = 0; i < nums.size(); i ++ ) {
            last = nums[i] + max(last, 0);//前一个的最大前缀和小于0的话，选择0
            res = max(res, last);
        }
        return res;
    }
};