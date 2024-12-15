/*
给定一个长度为 n 的整数数组 nums，数组中所有的数字都在 0∼n−1 的范围内。

数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。

请找出数组中任意一个重复的数字。

注意：如果某些数字不在 0∼n−1 的范围内，或数组中不包含重复数字，则返回 -1；
*/
//wwb
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        bool st[1010];
        memset(st, 0, sizeof st);
        int ans = -1;
        for (int i = 0; i < nums.size(); i ++)
        {
            if (nums[i] < 0 || nums[i] >= nums.size())  return -1;
            if (st[nums[i]])   ans = nums[i];
            st[nums[i]] = true;
        }
        return ans;
    }
};