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
//将指针i定义在外面，判定[0]这种数据，最后跳出for()循环，i ++，所以缺失的是1。
class Solution {
public:
    int getMissingNumber(vector<int>& A) {
        int i = 0;
        for(i = 0; i < A.size(); i ++)
            if(i != A[i])
                return i;
        return i;
    }
};


//leetcode,还需要手动排序
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size() + 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return n - 1;
    }
};
