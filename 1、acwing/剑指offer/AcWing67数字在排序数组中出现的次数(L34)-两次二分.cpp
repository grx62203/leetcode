/*
统计一个数字在排序数组中出现的次数。

例如输入排序数组 [1,2,3,3,3,3,4,5] 和数字 3，由于 3 在这个数组中出现了 4 次，因此输出 4。

数据范围
数组长度 [0,1000]。

样例
输入：[1, 2, 3, 3, 3, 3, 4, 5] ,  3

输出：4
*/

class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        if (nums.empty()) return 0;
        //找到大于等于 target 的第一个
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= k) r = mid;
            else l = mid + 1;
        }
        if (nums[r] != k) return 0;
        int left = l;
         //找到小于等于 target 的最后一个
        l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= k) l = mid;
            else r = mid - 1;
        }
        return r - left + 1;
    }
};