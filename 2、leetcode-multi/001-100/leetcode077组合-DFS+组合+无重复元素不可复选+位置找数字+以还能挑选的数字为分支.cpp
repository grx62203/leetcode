/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。
1 <= n <= 20
1 <= k <= n
*/

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }
    void dfs(int n, int k, int start) {
        if (!k) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i <= n; i ++ ) {
            path.push_back(i);
            //只是进入下一个，往后更新了start，意思是组合而不是排列，有了12就不要21了
            dfs(n, k - 1, i + 1);
            path.pop_back();
        }
    }
};

