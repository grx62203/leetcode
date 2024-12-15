/*
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。
*/
//如果一个位置能够到达，那么这个位置左侧所有位置都能到达
//52ms

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) return false;//如果遍历到的地点i > 上一个循环中能到达的最远位置，那就说明到达不了i位置
            k = max(k, i + nums[i]);//k表示当前能走到的最远位置
        }
        return true;
    }
};
