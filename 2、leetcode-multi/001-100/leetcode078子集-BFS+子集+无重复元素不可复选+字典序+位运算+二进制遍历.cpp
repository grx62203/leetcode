/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
*/
//4ms
 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        //遍历 0 - 2^n , 所有位选择为1不选择为0的 所有选择状态
        for (int i = 0; i < 1 << n; i ++ ) {
            vector<int> path;
            for (int j = 0; j < n; j ++ )
            //判断i的第j位是不是1，如果是，加入子集
                if (i >> j & 1)
                    path.push_back(nums[j]);
            res.push_back(path);
        }

        return res;
    }
};
