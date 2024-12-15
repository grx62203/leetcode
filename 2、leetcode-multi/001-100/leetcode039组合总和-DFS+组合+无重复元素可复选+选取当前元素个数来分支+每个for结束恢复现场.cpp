/*
给定一个**无重复元素**的正整数数组 `candidates` 和一个正整数 `target` ，找出 `candidates` 中所有可以使数字和为目标数 `target` 的唯一组合。

`candidates` 中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是唯一的。 

对于给定的输入，保证和为 `target` 的唯一组合数少于 `150` 个。

**示例 1：*
输入: candidates = [2,3,6,7], target = 7
输出: [[7],[2,2,3]]


- `1 <= candidates.length <= 30`
- `1 <= candidates[i] <= 200`
- `candidate` 中的每个元素都是独一无二的。
*/

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        dfs(c, 0, target);
        return ans;
    }

    void dfs(vector<int>& c, int u, int target) {
        if (target == 0)  //说明已经凑够了target
        {
            ans.push_back(path);
            return;
        }
        
        if (u == c.size()) return; //枚举完了数，还没有凑够，无解

        //可以选0个，选i个不能超过target  //每一次for都要往下走一次，返回一次 ，返回若干次，这次dfs就结束了
        for (int i = 0; c[u] * i <= target; i ++ ) {
            dfs(c, u + 1, target - c[u] * i); //进入下一个枚举
            path.push_back(c[u]);             //每枚举一次，都要添加到方案里面
        }

        //恢复现场，此时选取第二个元素的所有for都是选取某个第一个元素的分支，所以需要所有a2结束后恢复现场，再对选取下一数量的第一个元素进行dfs
        for (int i = 0; c[u] * i <= target; i ++ ) {
            path.pop_back();
        }
    }
};
