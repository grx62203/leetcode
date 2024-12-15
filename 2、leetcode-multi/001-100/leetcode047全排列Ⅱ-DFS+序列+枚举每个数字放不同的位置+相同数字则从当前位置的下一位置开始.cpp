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
    
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> st;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        path = vector<int>(nums.size());
        st = vector<bool>(nums.size());
        dfs(nums, 0, 0);
        return res;
    }

    void dfs(vector<int>& nums, int u, int start)
    {
        if (u == nums.size()){
            res.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); i ++) //遍历每一个位置       //枚举当前数可以放在哪些位置
        {
            if (!st[i]){ //该位置没有放数
                st[i] = true;                                           //标记选过
                path[i] = nums[u];                                      //将当前指定数字放到未选过的位置
                int next = u + 1 < nums.size() && nums[u + 1] == nums[u] ? i + 1 : 0;//相同数后面的只能从上一数选择位置的后一个位置开始
                dfs(nums, u + 1, next);                                  //继续下一个数，如果i+1=i则指定下一个位置开始
                st[i] = false;                                           //恢复现场
                //path 不用恢复，每次会被覆盖。
            }
        }
    }
};