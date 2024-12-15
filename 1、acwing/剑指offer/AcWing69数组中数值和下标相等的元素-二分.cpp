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

//左边的值都比下标小，右边的大于等于
class Solution {
public:
    int getNumberSameAsIndex(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
        	//右区间的左端点
            int mid = l + r >> 1;
            if (nums[mid] - mid >= 0) r = mid;
            else l = mid + 1;
        }
        if (nums[r] != r) r = -1;
        return r;
    }
};
