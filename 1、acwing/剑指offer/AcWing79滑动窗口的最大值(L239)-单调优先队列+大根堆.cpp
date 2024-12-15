/*
给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。

例如，如果输入数组 [2,3,4,2,6,2,5,1] 及滑动窗口的大小 3，那么一共存在 6 个滑动窗口，它们的最大值分别为 [4,4,6,6,6,5]。

注意：

数据保证 k 大于 0，且 k 小于等于数组长度。
数据范围
数组长度 [1,1000]。

样例
输入：[2, 3, 4, 2, 6, 2, 5, 1] , k=3

输出: [4, 4, 6, 6, 6, 5]
*/

//leetcode太贱了，多了一个k=0的
//默认是大根堆
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || k == 0) return vector<int> {};
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i);
        }
        vector<int> ans = {q.top().first};
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k)  q.pop();
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
