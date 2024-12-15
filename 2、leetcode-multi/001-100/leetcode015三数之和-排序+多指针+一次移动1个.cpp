/*
给你一个包含 `n` 个整数的数组 `nums`，判断 `nums` 中是否存在三个元素 *a，b，c ，*使得 *a + b + c =* 0 ？请你找出所有和为 `0` 且不重复的三元组。

**注意：**答案中不可以包含重复的三元组。

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]

- `0 <= nums.length <= 3000`
- `-105 <= nums[i] <= 105`
*/

/*
当i确定后，j k 就可以做双指针了
j越大，k越小
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++ ) {
        	//i 等于上一个的时候，去重，跳出循环但继续
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1, k = nums.size() - 1; j < k; j ++ ) {
            	//j 等于上一个的时候，去重，跳出循环但继续
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                //k 向前移动的过程，当k-1 对应的组小于0的时候，再判断当前k对应的组
                while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= 0) k -- ;
                if (j == k) break;
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }

        return res;
    }
};