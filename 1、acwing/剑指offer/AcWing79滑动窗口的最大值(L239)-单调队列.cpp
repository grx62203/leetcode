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

class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;

        for (int i = 0; i < nums.size(); i ++ ) {
        	//维护窗口移动
            while (q.size() && q.front() <= i - k) q.pop_front();
            //维护单调队列的递减性，有比i对应的还小，就pop
            while (q.size() && nums[q.back()] <= nums[i]) q.pop_back();
            //维护窗口移动
            q.push_back(i);
            //当第一个窗口成形后，一直输出维持窗口移动的递减单调序列的第一个
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }

        return res;
    }
};

//数组模拟单调队列
class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        int q[100001];
        int hh=0,tt=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(hh<=tt&&i-q[hh]>=k) hh++;
            while(hh<=tt&&nums[q[tt]]<nums[i]) tt--;
            q[++tt]=i;
            if(i>=k-1) ans.push_back(nums[q[hh]]);
        }
        return ans;
    }
};
