/*
给定一个可包含重复数字的序列 `nums` ，**按任意顺序** 返回所有不重复的全排列。

**示例 1：**
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]

- `1 <= nums.length <= 8`
- `-10 <= nums[i] <= 10`
*/

//保证相同数字 的相对顺序不变
class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> st;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());                        //排序之后，相同的数字就会排在一起，然后每次用第一个没有用过的数
        path = vector<int>(nums.size());
        st = vector<bool>(nums.size());
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int>&nums, int u) {
        if (u == nums.size()) {// 所有的位置都已使用
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i ++ ) {//遍历每一个数字       //枚举当前位置可以选择哪些数
            if (!st[i]) {//该数字没有使用过
                if (i && nums[i - 1] == nums[i] && !st[i - 1]) continue;//连续的几个重复的数字，每次只选择第一个没有使用过的
                st[i] = true;                                        //标记选过
                path[u] = nums[i];                                   //将未使用过的数字放到指定位置
                dfs(nums, u + 1);                                    //继续下一个位置
                st[i] = false;                                       //恢复现场
                //path 不用恢复，每次会被覆盖。
            }
        }
    }
};
