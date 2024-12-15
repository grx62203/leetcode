/*
从扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这 5 张牌是不是连续的。

2∼10 为数字本身，A 为 1，J 为 11，Q 为 12，K 为 13，大小王可以看做任意数字。

为了方便，大小王均以 0 来表示，并且假设这副牌中大小王均有两张。

样例1
输入：[8,9,10,11,12]

输出：true
样例2
输入：[0,8,9,11,12]

输出：true
*/


//这个题解没办法判断循环的顺子 [1, 10, 11, 12, 13]
class Solution {
public:
    bool isContinuous( vector<int> nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i ++ )
        	//如果这个数不是大小王，且连续两个相同
            if (nums[i] && nums[i] == nums[i - 1])  return false;
        //遍历非0的数组元素，如果出现最后一个与当前元素之差大于4的情况，则false
        //1 2 0 4 5 就算sort后，也可以保证返回true
        for (auto x : nums)
            if (x)  return nums.back() - x <= 4;
    }
};
