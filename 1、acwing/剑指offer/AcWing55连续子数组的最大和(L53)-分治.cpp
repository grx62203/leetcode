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
取数组中心点为中心
    最大子序要么全在中心左边，要么在右边，要么跨中心。分三种情况进行考虑
    跨中心的情况，再分治成中心点左侧和右侧的最大子序和问题。
*/
//leetcode
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        result = maxSubArrayHelper(nums, 0, numsSize - 1);
        return result;
    }

    int maxSubArrayHelper(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }
        int mid = (left + right) / 2;
        //左边的最大子数组和
        int leftSum = maxSubArrayHelper(nums, left, mid);
        //右边的最大子数组和
        int rightSum = maxSubArrayHelper(nums, mid + 1, right);//注意这里应是mid + 1，否则left + 1 = right时，会无限循环
        //跨越左右两边的最大子数组和
        int midSum = findMaxCrossingSubarray(nums, left, mid, right);
        //三者最大为result
        int result = max(leftSum, rightSum);
        result = max(result, midSum);
        return result;
    }

    int findMaxCrossingSubarray(vector<int> &nums, int left, int mid, int right)
    {
        int leftSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = INT_MIN;
        sum = 0;
        //注意这里i = mid + 1，避免重复用到nums[i]
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        return (leftSum + rightSum);
    }
};