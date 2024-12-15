/*
和谐数组是指一个数组里元素的最大值和最小值之间的差别 **正好是 `1`** 。

现在，给你一个整数数组 `nums` ，请你在所有可能的子序列中找到最长的和谐子序列的长度。

数组的子序列是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。
*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto c: nums) cnt[c] ++ ;
        int res = 0;
        for (auto [k, v]: cnt)
            if (cnt.count(k - 1))
                res = max(res, cnt[k] + cnt[k - 1]);
        return res;
    }
};
