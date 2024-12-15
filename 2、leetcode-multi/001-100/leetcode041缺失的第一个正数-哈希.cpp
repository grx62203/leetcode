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

//需要优化
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto& x : nums)   hash.insert(x);
        int res = 1;
        while(hash.count(res)) res++;
        return res;
    }
};