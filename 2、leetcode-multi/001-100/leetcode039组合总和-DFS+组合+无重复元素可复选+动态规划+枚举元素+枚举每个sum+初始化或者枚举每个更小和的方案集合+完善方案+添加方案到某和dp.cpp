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

/*
由于之前做了这一题：零钱兑换，想到了一个动态规划的解法：

1、定义一个三维数组，长度为target + 1

2、首先使用每个元素进行遍历组合

2.1、假设为candidates的第x个元素进行组合，取d = candidates[x]，组合的sum为i，则有三种情况

-->如果d大于i，直接跳过，不存在这样的方案，不需要考虑

-->如果d等于i，那么这是一个独立的组合，直接push_pack（类似于零钱兑换的dp[0] = 1）

-->如果d小于i，把dp中的i - d的所有方案的尾部增加d
*/

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<vector<int>>> dp(target + 1);
	for (auto &d : candidates) {
		//遍历dp[d]到dp[target]
		for (int i = d; i <= target; i++) {
			auto &cur = dp[i];
			if (i == d) {
				cur.push_back({d});     //dp[i]的初始方案，只选择了当前d，且和为i
			} else {
				auto &pre = dp[i - d];
				for (auto v : pre) {
					v.push_back(d);     //dp[i-1]对应的每个方案复制出来，此时每个方案和为i-d，再都加上d
					cur.push_back(v);   //dp[i]  把dp[i-1]的每一个方案复制累加新结果v都累加上
				}
			}
		}
	}
	//dp[target]对应的方案和都是target吗？,dp[i]的每个方案添加元素后和都是dp[i]
	return dp[target];
}