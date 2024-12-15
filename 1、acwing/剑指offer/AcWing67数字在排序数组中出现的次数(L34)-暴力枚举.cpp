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
        int cnt = 0;
        for(int x : nums)
            if(x == k)
                cnt++;
        return cnt;
    }
};