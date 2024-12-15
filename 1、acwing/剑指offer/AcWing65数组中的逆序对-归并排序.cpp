/*
在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。

输入一个数组，求出这个数组中的逆序对的总数。

数据范围
给定数组的长度 [0,100]。

样例
输入：[1,2,3,4,5,6,0]

输出：6
*/
//归并排序可以使用自顶向下的方式递归实现，也可以使用自底向上的方式迭代实现
class Solution {
public:

    int merge(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;
        int mid = l + r >> 1;
        int res = merge(nums, l, mid) + merge(nums, mid + 1, r);
        //归并核心
    	//下面是双指针缝合两个有序数组为一个有序数组，相当于合并有序链表
        vector<int> temp;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r)
            if (nums[i] <= nums[j]) temp.push_back(nums[i ++ ]);
            else {
                temp.push_back(nums[j ++ ]);
                res += mid - i + 1;//后面的元素小于前面的元素 的数量 = 前半部分的后面的数，与j 都是逆序对
            }
        while (i <= mid) temp.push_back(nums[i ++ ]);
        while (j <= r) temp.push_back(nums[j ++ ]);
        //物归原主
        int k = l;
        for (auto x : temp) nums[k ++ ] = x;
        return res;
    }

    int inversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size() - 1);
    }
};
