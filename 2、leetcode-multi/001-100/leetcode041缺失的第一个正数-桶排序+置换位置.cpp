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
        //为空，缺失1
        if (!n) return 1;
		//将下标 映射 减去1，变成 0-n
        for (auto& x : nums)
            if (x != INT_MIN) x -- ;//可能会越界、边界判定。需要特判

        //0-n的正数，最后的结果是能回到重定位位置的都回去了，回不去的那个下标，说明那个下标对应正数不存在
        for (int i = 0; i < n; i ++ ) {
            while (nums[i] >= 0 && nums[i] < n && nums[i] != i && nums[i] != nums[nums[i]])
                //将数nums[i] 交换到下标nums[i]对应的位置
                swap(nums[i], nums[nums[i]]);
        }

        for (int i = 0; i < n; i ++ )
            if (nums[i] != i)
                return i + 1;

        return n + 1;
    }
};