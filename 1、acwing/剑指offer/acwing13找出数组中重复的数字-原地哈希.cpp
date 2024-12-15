/*
给定一个长度为 n 的整数数组 nums，数组中所有的数字都在 0∼n−1 的范围内。

数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。

请找出数组中任意一个重复的数字。

注意：如果某些数字不在 0∼n−1 的范围内，或数组中不包含重复数字，则返回 -1；
*/
//每次swap操作都会将一个数放在正确的位置上，最后一次swap会将两个数同时放到正确位置上，一共只有 n 个数和 n 个位置，所以swap最多会进行 n−1 次。所以总时间复杂度是 O(n)
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size();
        for (auto x : nums)
            if (x < 0 || x >= n)
                return -1;
        for (int i = 0; i < n; i ++ ) {
            while (nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
            if (nums[i] != i) return nums[i];
        }
        return -1;
    }
};

