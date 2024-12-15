/*
给你一个由 `n` 个整数组成的数组 `nums` ，和一个目标值 `target` 。请你找出并返回满足下述全部条件且**不重复**的四元组 `[nums[a], nums[b], nums[c], nums[d]]` （若两个四元组元素一一对应，则认为两个四元组重复）：

- `0 <= a, b, c, d < n`
- `a`、`b`、`c` 和 `d` **互不相同**
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

你可以按 **任意顺序** 返回答案 。
- `1 <= nums.length <= 200`
- `-109 <= nums[i] <= 109`
- `-109 <= target <= 109`
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4)   return res;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i < length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; 
            if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break; 
            if ((long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target)  continue; 
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; 
                if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)  break;
                if ((long) nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target)  continue; 
                int left = j + 1, right = length - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];//溢出的可能性在前面longlong被特判了
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])  left++;//避免重复
                        left++;//正常移动
                        while (left < right && nums[right] == nums[right - 1])  right--;//避免重复
                        right--;//正常移动
                    } 
                    else if (sum < target) left++;
                    else  right--;
                }
            }
        }
        return res;
    }
};