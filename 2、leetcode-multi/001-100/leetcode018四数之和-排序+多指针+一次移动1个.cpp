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

//如果是有n个数相加，就是背包w
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4)   return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++ ) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j ++ ) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                for (int k = j + 1, u = nums.size() - 1; k < u; k ++ ) {
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    //while (u - 1 > k && nums[i] + nums[j] + nums[k] + nums[u - 1] >= target) u -- ;会溢出
                    while (k < u - 1 && nums[i] + nums[j] -target >= - nums[k] - nums[u - 1] ) u -- ;
                    //if (nums[i] + nums[j] + nums[k] + nums[u] == target){ 会溢出，需要修改
                    if (nums[i]+nums[j]-target==-nums[k]-nums[u]){
                        res.push_back({nums[i], nums[j], nums[k], nums[u]});
                    }
                }
            }
        }
        return res;
    }
};