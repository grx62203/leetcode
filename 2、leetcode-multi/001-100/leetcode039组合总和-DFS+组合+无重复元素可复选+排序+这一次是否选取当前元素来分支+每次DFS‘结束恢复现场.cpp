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
    void solve(int i, vector<int>& candidates, int sum,
             vector<int> &ch, int target, vector<vector<int>>& ans) {
        // 注意这里的 ch 是引用。
        if (sum == target) { // 找到目标值，添加答案。
            ans.push_back(ch);
            return;
        }
        if (i == candidates.size() || sum > target) // 超出范围回溯。
            return;

        //不选取当前元素
        solve(i + 1, candidates, sum, ch, target, ans);

        //选取当前元素
        ch.push_back(candidates[i]);
        solve(i, candidates, sum + candidates[i], ch, target, ans);
        ch.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> ch; // ch 记录已选择的数字。
        //从0开始、总候选、累计和、已经选择的数字=path、目标值、存放path的答案
        solve(0, candidates, 0, ch, target, ans);

        return ans;
    }
};