/*
假设一个单调递增的数组里的每个元素都是整数并且是唯一的。

请编程实现一个函数找出数组中任意一个数值等于其下标的元素。

例如，在数组 [−3,−1,1,3,5] 中，数字 3 和它的下标相等。

数据范围
数组长度 [1,100]。

样例
输入：[-3, -1, 1, 3, 5]

输出：3
注意:如果不存在，则返回-1。
*/

class Solution {
public:
    int getNumberSameAsIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == i)
                return i;
        return -1;
    }
};