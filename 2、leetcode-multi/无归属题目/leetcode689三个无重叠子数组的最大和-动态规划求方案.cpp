/*
给你一个整数数组 `nums` 和一个整数 `k` ，找出三个长度为 `k` 、互不重叠、且 `3 * k` 项的和最大的子数组，并返回这三个子数组。

以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置（下标从 **0** 开始）。如果有多个结果，返回字典序最小的一个。
*/

可以得到前 i 个数里面找 j 个长度为 k 的不重叠数组的最大和为   f（i，j）
这个公示-正序DP选出来的结果是先遇到先选择
1、逆序dp，类似背包方案
2、下标更改，最后输出答案别忘



class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1);                                           //表示前缀和
        for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + nums[i - 1];   //预处理前缀和，更改数组下标了
        vector<vector<int>> f(n + 2, vector<int>(4));                   //状态数组，需要用到 n+1 这个下标，所以这里就是n+2

        int x = n + 1, y = 3;
        //x 、y 的开始
        //逆序DP，和DP相反，从后向前换个方向
        for (int i = n - k + 1; i; i -- )     //最后一段的最多可以从   n—k+1 开始
        {
            for (int j = 1; j <= 3; j ++ )
                f[i][j] = max(f[i + 1][j], f[i + k][j - 1] + s[i + k - 1] - s[i - 1]);
                //max(不用ai时候的f（i-1，j）， 用ai时候的f（i-k，j-1）+ 前缀和求的子数组和）     i是逆序，-1变成 +1
            if (f[x][3] <= f[i][3]) x = i;   //从后往前，找到了最后一个最大值所在的i，即字典序最小的要求
        }

        vector<int> res;
        //答案数组
        while (y) {
            while (f[x][y] != f[x + k][y - 1] + s[x + k - 1] - s[x - 1]) x ++ ;
            //当移动到被选择了的的位置，退出循环，加入下标   
            res.push_back(x - 1);   //下标被动选择成了从1开始，所以减去一个 1，添加的顺序是y从大到小的一个排序
            x += k, y -- ;          //x递进到当前子数组最后一个元素的 下一个
        }
        return res;
    }
};