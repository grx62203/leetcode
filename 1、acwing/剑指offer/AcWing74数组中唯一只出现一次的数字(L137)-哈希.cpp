/*
在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。

请找出那个只出现一次的数字。

你可以假设满足条件的数字一定存在。

思考题：

如果要求只使用 O(n) 的时间和额外 O(1) 的空间，该怎么做呢？
数据范围
数组长度 [1,1500]。

样例
输入：[1,1,1,2,2,2,3,4,4,4]

输出：3
*/

//leetcode
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            ++freq[num];
        }
        int ans = 0;
        for (auto [num, occ]: freq) {
            if (occ == 1) {
                ans = num;
                break;
            }
        }
        return ans;
    }
};
