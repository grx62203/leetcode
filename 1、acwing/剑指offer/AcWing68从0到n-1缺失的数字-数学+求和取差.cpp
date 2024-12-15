/*
一个长度为 n−1 的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围 0 到 n−1 之内。

在范围 0 到 n−1 的 n 个数字中有且只有一个数字不在该数组中，请找出这个数字。

数据范围
1≤n≤1000
样例
输入：[0,1,2,4]

输出：3
*/
//已经排序
class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        int s = nums.size() * (nums.size() + 1) / 2;
        for (auto x : nums) s -= x;
        return s;
    }
};

//已经排序
class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(auto &x:nums) sum+=x;
        return n*(n+1)/2-sum;
    }
};