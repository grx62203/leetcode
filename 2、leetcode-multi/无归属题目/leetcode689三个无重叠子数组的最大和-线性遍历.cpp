/*
给你一个整数数组 `nums` 和一个整数 `k` ，找出三个长度为 `k` 、互不重叠、且 `3 * k` 项的和最大的子数组，并返回这三个子数组。

以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置（下标从 **0** 开始）。如果有多个结果，返回字典序最小的一个。
*/

(线性遍历) O(n)O(n)
1、将 nums 数组变为 sum 数组，其中 sum(i)=∑i+k−1j=inums(j)sum(i)=∑j=ii+k−1nums(j)，
即 sum 数组的每一项都是 nums 数组中对应 k 项的和。
2、题目可以转化为，在 sum 数组中取三个位置 x, y, z，满足 x+k<=yx+k<=y 且 y+k<=zy+k<=z。
3、对 sum 数组，求前缀最大值数组 l，以及后缀最大值数组 r。
l[i] 表示 sum 数组中前 i 个数字的最大值的位置，
r[i] 表示 sum 数组中第 i 个到末尾最大值的位置。如果最大值相同，则取位置靠前的。
4、从 k 到 n - k - k 枚举中间的数字的位置 y。
对于每个位置 i，如果 sum[l[i - k]] + sum[i] + sum[r[i + k]] 比答案大，则更新答案。
如果和答案一致，则比较 x 的字典序然后更新答案。
时间复杂度
每个位置仅遍历常数次，故时间复杂度为 O(n)O(n)。

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n - k + 1);
        int t = 0;
        for (int i = 0; i < k - 1; i++)
            t += nums[i];

        for (int i = k - 1; i < n; i++) {
            t += nums[i];
            sum[i - k + 1] = t;
            t -= nums[i - k + 1];
        }

        vector<int> l(n - k + 1), r(n - k + 1);

        l[0] = 0;
        for (int i = 1; i < n - k + 1; i++)
            if (sum[l[i - 1]] >= sum[i]) {
                l[i] = l[i - 1];
            } else {
                l[i] = i;
            }

        r[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; i--)
            if (sum[r[i + 1]] > sum[i]) {
                r[i] = r[i + 1];
            } else {
                r[i] = i;
            }

        int x, y, z, ans = 0;
        for (int i = k; i < n - k + 1 - k; i++)
            if (ans < sum[l[i - k]] + sum[i] + sum[r[i + k]]) {
                ans = sum[l[i - k]] + sum[i] + sum[r[i + k]];
                x = l[i - k];
                y = i;
                z = r[i + k];
            } else if (ans == sum[l[i - k]] + sum[i] + sum[r[i + k]]) {
                if (x > l[i - k]) {
                    x = l[i - k];
                    y = i;
                    z = r[i + k];
                }
            }

        return {x, y, z};
    }
};