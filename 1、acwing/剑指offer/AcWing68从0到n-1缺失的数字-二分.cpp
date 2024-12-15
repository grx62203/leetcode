/*
一个长度为 n−1 的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围 0 到 n−1 之内。

在范围 0 到 n−1 的 n 个数字中有且只有一个数字不在该数组中，请找出这个数字。

数据范围
1≤n≤1000
样例
输入：[0,1,2,4]

输出：3
*/
/*
从中可以看出，数组左边蓝色部分都满足nums[i] == i，数组右边橙色部分都不满足nums[i] == i，因此我们可以二分出分界点 x 的值。
另外要注意特殊情况：当所有数都满足nums[i] == i时，表示缺失的是 n-1。
*/
//已经排序
class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        if (nums.empty()) return 0;

        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            //右区间的左端点
            int mid = l + r >> 1;
            if (nums[mid] != mid) r = mid;
            else l = mid + 1;
        }

        if (nums[r] == r) r ++ ;
        return r;
    }
};


//没有边界也可以ac，是因为r取值？
class Solution {
public:
    int getMissingNumber(vector<int>& A) {
        int l = 0, r = A.size();
        while(l < r)
        {
            int mid = l + r >> 1;
            if(A[mid] != mid) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};



//java
class Solution {
    public int getMissingNumber(int[] nums) {
        if(nums.length < 1) return 0;
        int l = 0, r = nums.length - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] != mid) r = mid;
            else l = mid + 1;
        }
        return l == nums[l] ? l + 1 : l;
    }
};


