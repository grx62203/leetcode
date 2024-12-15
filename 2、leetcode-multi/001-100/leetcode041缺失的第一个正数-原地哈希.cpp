/*
给你一个未排序的整数数组 `nums` ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 `O(n)` 并且只使用常数级别额外空间的解决方案。


**示例 1：**

输入：nums = [1,2,0]
输出：3

**提示：**

- `1 <= nums.length <= 5 * 105`
- `-231 <= nums[i] <= 231 - 1`
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        //去掉负数影响
        for (int& num: nums) {
            if (num <= 0)    num = n + 1;
        }
        //将小于n的正数 化为下标   1对应0、2对应1、、、、，将正数重定位位置的数组值化负
        //那么没有化负的数组值下标对应的正数（i+1）也就是没有被重定向，也就是没有出现过
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n)   nums[num - 1] = -abs(nums[num - 1]); 
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0)   return i + 1;
        }
        return n + 1;
    }
};