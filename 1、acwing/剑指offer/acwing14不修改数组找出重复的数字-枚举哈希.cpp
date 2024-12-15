/*
给定一个长度为 n+1 的数组nums，数组中所有的数均在 1∼n 的范围内，其中 n≥1。

请找出数组中任意一个重复的数，但不能修改输入的数组。

数据范围
1≤n≤1000
*/
//wwb
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        bool st[1010];
        memset(st, 0, sizeof st);

        for (int i = 0; i < nums.size(); i ++)
        {
            if (st[nums[i]])  return nums[i];
            st[nums[i]] = true;
        }
        return -1;
    }
};