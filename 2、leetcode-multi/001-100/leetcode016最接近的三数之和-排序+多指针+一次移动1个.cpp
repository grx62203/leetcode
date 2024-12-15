/*
给你一个长度为 `n` 的整数数组 `nums` 和 一个目标值 `target`。请你从 `nums` 中选出三个整数，使它们的和与 `target` 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。\

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。

- `3 <= nums.length <= 1000`
- `-1000 <= nums[i] <= 1000`
- `-104 <= target <= 104`
*/

//先固定i， 枚举j与k
//求取唯一答案，那么就需要比较 小于目标 和 大于目标 两种情况的极限
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        //需要保存最小值
        pair<int, int> res(INT_MAX, INT_MAX);
        for (int i = 0; i < nums.size(); i ++ ){
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1, k = nums.size() - 1; j < k; j ++ ) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;、
                //k-1与k-1对应的和 都大于j、target的时候，k肯定不是答案，所以递减
                while (k - 1 > j && nums[i] + nums[j] + nums[k - 1] >= target) k -- ;
                int s = nums[i] + nums[j] + nums[k];
                res = min(res, make_pair(abs(s - target), s));//比较pair的第一个
                //但是当k-1<=j，意味着k-1不是k-1了，对应其他的三元组
                if (k - 1 > j) {
                    s = nums[i] + nums[j] + nums[k - 1];
                    res = min(res, make_pair(target - s, s));
                }
            }
        }
        return res.second;
    }
};