/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。

请写程序找出这两个只出现一次的数字。

你可以假设这两个数字一定存在。

数据范围
数组长度 [1,1000]。

样例
输入：[1,2,3,3,4,4]

输出：[1,2]
*/

class Solution {
public:
    vector<int> findNumsAppearOnce(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> hash;
        for (auto x : nums)
            hash[x]++;
        for (auto x : nums)
            if (hash[x] == 1)
                ans.push_back(x);
        return ans;
    }
};
