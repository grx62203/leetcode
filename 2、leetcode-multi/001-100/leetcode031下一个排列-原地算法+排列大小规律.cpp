/*
实现获取 **下一个排列** 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列（即，组合出下一个更大的整数）。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须**[ 原地 ](https://baike.baidu.com/item/原地算法)**修改，只允许使用额外常数空间。

输入：nums = [1,2,3]
输出：[1,3,2]

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 100`
*/

//保证前面的位数不变，变低位，从后往前考虑
//前后数字降序，前面一位不可能变大
//从后向前找到第一对非降序的位置，前一个数可以变大为后面排列的最小数，然后将钱一个数与后面剩余排列合并改为升序
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 1;
        while (k > 0 && nums[k - 1] >= nums[k]) k -- ;   //从后向前走，找到第一个<非降序对>，k是<对右>
        if (k <= 0)  reverse(nums.begin(), nums.end());  //如果整体都是降序，翻转
        else {
            int t = k;
            while (t < nums.size() && nums[t] > nums[k - 1]) t ++ ;  //从k向后找到第一个小于等于<对左>值的，为t，则t-1大于<对左>值
            swap(nums[t - 1], nums[k - 1]);                          //交换<对左>值 与 <队右>后面最后一个大于<对左>值的值
            reverse(nums.begin() + k, nums.end());                   //翻转后面的降序序列为升序序列，可以保证交换后后面也是降序
        }
    }
};


/*
注意到下一个排列总是比当前排列要大，除非该排列已经是最大的排列。我们希望找到一种方法，能够找到一个大于当前序列的新序列，且变大的幅度尽可能小。具体地：

我们需要将一个左边的「较小数」与一个右边的「较大数」交换，以能够让当前排列变大，从而得到下一个排列。

同时我们要让这个「较小数」尽量靠右，而「较大数」尽可能小。当交换完成后，「较大数」右边的数需要按照升序重新排列。这样可以在保证新排列大于原来排列的情况下，使变大的幅度尽可能小。
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])  i--;  //i是从后向前第一个非降序对的对左 
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j])  j--;  //j是从后向前第一个大于对左值的位置
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
