/*
给你一个非负整数数组 `nums` ，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
假设你总是可以到达数组的最后一个位置。


**示例 1:**
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
- `1 <= nums.length <= 104`
- `0 <= nums[i] <= 1000`
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 0x3f3f3f3f);
        for (int i = 0; i < n; i++) {
            if (!i) f[i] = 0; // 处理边界
            else {
                for (int j = 0; j < i; j++) { 
                	// 只要前面的点能跳到i点就更新最小值
                    if (j + nums[j] >= i) { 
                        f[i] = min(f[i], f[j] + 1);
                    }
                }
            }
        }
        return f[n - 1];
    }
};