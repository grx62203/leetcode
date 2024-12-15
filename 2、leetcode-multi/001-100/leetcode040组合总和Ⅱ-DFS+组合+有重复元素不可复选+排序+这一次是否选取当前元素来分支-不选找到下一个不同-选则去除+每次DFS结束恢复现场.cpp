/*
给定一个数组 `candidates` 和一个目标数 `target` ，找出 `candidates` 中所有可以使数字和为 `target` 的组合。

`candidates` 中的每个数字在每个组合中只能使用一次。

**注意：**解集不能包含重复的组合。 

 

**示例 1:**

```
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```

**提示:**

- `1 <= candidates.length <= 100`
- `1 <= candidates[i] <= 50`
- `1 <= target <= 30`
*/
/*
(递归枚举)
做法与 Combination Sum 很类似，只不过本题是每个数字仅用一次。
此题仍然需要排序，目的是为了防止重复。
防止重复的方法是，搜索时如果不想要当前层的数字，则需要找到下一个与之不同的数字才可以进行下一层的搜索。
*/

class Solution {
public:
    void solve(int i, vector<int>& candidates, int sum, vector<int>& ch, int target, vector<vector<int>>& ans) {// 注意这里的 ch 是引用。
        if (sum == target) {
            ans.push_back(ch);
            return;
        }
        if (i == candidates.size() || sum > target)
            return;

        for (int j = i + 1; j < candidates.size(); j++)
            if (candidates[j] != candidates[i]) {
                // 不用该层的数字时，需要找到下一个不同的数字。
                solve(j, candidates, sum, ch, target, ans);
                break;
            }

        // 选择该层的数字。
        ch.push_back(candidates[i]);
        solve(i + 1, candidates, sum + candidates[i], ch, target, ans);
        ch.pop_back();
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> ch; // ch 记录选择的数字。
        solve(0, candidates, 0, ch, target, ans);
        return ans;
    }
};
