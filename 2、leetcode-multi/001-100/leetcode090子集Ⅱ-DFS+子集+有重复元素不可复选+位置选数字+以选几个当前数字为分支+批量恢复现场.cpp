/*
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
*/

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            ans.push_back(path);
            return;
        }

        int k = u + 1;
        while (k < nums.size() && nums[k] == nums[u]) k ++ ;

        /*
        ps1、0个特殊处理
        // 当前枚举的数有 k - u 个，枚举其选多少次 0~ k - u次
        dfs(nums, k) ; // 一个都不选
        for(int i = 1; i <= k - u; i ++) // 枚举选的次数
        {
            path.push_back(nums[u]);
            dfs(nums, k);
        }
        */

        for (int i = 0; i <= k - u; i ++ ) {
            dfs(nums, k);
            //ps1:dfs在 push_back之前，这样可以枚举出选0个、1个、… k - u个当前数的情况。
            path.push_back(nums[u]);
        }
        
        //ps2:选择了若干个nums[u]之后，要批量恢复现场
        for (int i = 0; i <= k - u; i ++ ) {
            path.pop_back();
        }
    }
};



//若发现没有选择上一个数，且当前数字与上一个数相同，则可以跳过当前生成的子集。
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(bool choosePre, int cur, vector<int> &nums) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        dfs(false, cur + 1, nums);
        if (!choosePre && cur > 0 && nums[cur - 1] == nums[cur]) {
            return;
        }
        t.push_back(nums[cur]);
        dfs(true, cur + 1, nums);
        t.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        dfs(false, 0, nums);
        return ans;
    }
};
作者：LeetCode-Solution
链接：https://leetcode.cn/problems/subsets-ii/solution/zi-ji-ii-by-leetcode-solution-7inq/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。