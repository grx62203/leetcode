/*
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。
*/
//64ms

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        return helper(nums, nums.size()-1);
    }

    bool helper(vector<int>& nums, int last)
    {
        if(last == 0 && nums[0] > 0) return true;
        //遍历前面的每一个，只要有一个返回了true，那就代表能从前面到达这个位置，return true
        for(int i=1;i<=last;++i)
        {
            //从后向前枚举的元素可以到达最后一行, 结果便取决于是否能到达该元素处，层次递归向前
            if(nums[last-i] >= i)       return helper(nums, last-i);
        }
        return false;
    }
};
