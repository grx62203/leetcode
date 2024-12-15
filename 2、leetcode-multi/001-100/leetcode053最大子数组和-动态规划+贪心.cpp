/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组 是数组中的一个连续部分。
*/

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

/*
dp代表包含当前位置的左串的最大前缀和 = max（包括当前值的前缀和，当前值）
dp[i] = max(dp[i-1] + nums[i], nums[i]);
ans = max(ans, dp);
*/
//80ms
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

/*
当前面的字串和小于0的时候
    后一个是正数 优先选择后一个单个字符更优
    后一个是负数 不选择后一个的前串更优
所以当某个字串小于0的时候，就情况sum，再从后一个开始从新子串累加
*/
//96ms
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int n = int(nums.size());
        if (!n) return 0;
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            ans = max(ans, sum);//每次更新sum都要计算max
            if(sum < 0) sum = 0;
        }
        return ans;
    }
};