/*
一个长度为 n−1 的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围 0 到 n−1 之内。

在范围 0 到 n−1 的 n 个数字中有且只有一个数字不在该数组中，请找出这个数字。

数据范围
1≤n≤1000
样例
输入：[0,1,2,4]

输出：3
*/

//leetcoded
//此对上述 2n - 1 个整数进行按位异或运算，结果即为缺失的数字。
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size() + 1;
        for (int i = 0; i < n - 1; i++) {
            res ^= nums[i];
        }
        for (int i = 0; i <= n - 1; i++) {
            res ^= i;
        }
        return res;
    }
};


