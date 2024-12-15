/*
给定一个不含重复数字的数组 `nums` ，返回其 **所有可能的全排列** 。你可以 **按任意顺序** 返回答案。

**示例 1：**
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

- `1 <= nums.length <= 6`
- `-10 <= nums[i] <= 10`
- `nums` 中的所有整数 **互不相同**
*/

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> st;

    vector<vector<int>> permute(vector<int>& nums) {
        path = vector<int>(nums.size());
        st = vector<bool>(nums.size()); //记录 数字 的使用情况

        dfs(nums, 0);

        return ans;
    }

    void dfs(vector<int>& nums, int u) {                             //u表示枚举到了方案数组path的哪个位置
        if (u == nums.size()) {//所有的数字已使用
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i ++ ) {//遍历每一个数字       //枚举当前位置可以选择哪些数
            if (st[i] == false) {//该数字没有使用过
                st[i] = true;                                         //标记选过
                path[u] = nums[i];                                    //将未使用过的数字放到指定位置
                dfs(nums, u + 1);                                     //继续下一个位置
                st[i] = false;                                        //恢复现场
                //path 不用恢复，每次会被覆盖。
            }
        }
    }
};