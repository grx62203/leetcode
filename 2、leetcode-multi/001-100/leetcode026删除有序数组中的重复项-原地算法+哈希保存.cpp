/*
给你一个有序数组 `nums` ，请你**[ 原地](http://baike.baidu.com/item/原地算法)** 删除重复出现的元素，使每个元素 **只出现一次** ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 **[原地 ](https://baike.baidu.com/item/原地算法)修改输入数组** 并在使用 O(1) 额外空间的条件下完成。


**说明:**
为什么返回数值是整数，但输出的答案是数组呢?
请注意，输入数组是以**「引用」**方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
你可以想象内部操作如下:
// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

- `0 <= nums.length <= 3 * 104`
- `-104 <= nums[i] <= 104`
- `nums` 已按升序排列
*/
 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i ++ )
            if (!i || nums[i] != nums[i - 1])
                nums[k ++ ] = nums[i];//将每次与前一个不一样的重新放到前面，形成新的数组，k先用后增，得长度
        return k;
    }
};




/*
/为了让解法更具有一般性，我们将原问题的「最多保留 1 位」修改为「最多保留 k 位」。
对于此类问题，我们应该进行如下考虑：

由于是保留 k 个相同数字，对于前 k 个数字，我们可以直接保留。
对于后面的任意数字，能够保留的前提是：与当前写入的位置前面的第 k 个元素进行比较，不相同则保留。
举个🌰，我们令 k=1，假设有样例：[3,3,3,3,4,4,4,5,5,5]

设定变量 idx，指向待插入位置。idx 初始值为 0，目标数组为 []
首先我们先让第 1 位直接保留（性质 1）。idx 变为 1，目标数组为 [3]
继续往后遍历，能够保留的前提是与 idx 的前面 1 位元素不同（性质 2），因此我们会跳过剩余的 3，将第一个 4 追加进去。idx 变为 2，目标数组为 [3,4]
继续这个过程，跳过剩余的 4，将第一个 5 追加进去。idx 变为 3，目标数组为 [3,4,5]
当整个数组被扫描完，最终我们得到了目标数组 [3,4,5] 和 答案 idx 为 3。
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return process(nums,1);
    }
    int process(vector<int>& nums,int k){
        int idx = 0;
        for(auto x : nums){
            if(idx < k || nums[idx - k] != x){
                nums[idx++] = x;
            }
        }
        return idx;  
    }
};

/*
基于上述解法我们还能做一点小剪枝：利用目标数组的最后一个元素必然与原数组的最后一个元素相同进行剪枝，从而确保当数组有超过 k 个最大值时，数组不会被完整扫描。
但需要注意这种「剪枝」同时会让我们单次循环的常数变大，所以仅作为简单拓展。
*/