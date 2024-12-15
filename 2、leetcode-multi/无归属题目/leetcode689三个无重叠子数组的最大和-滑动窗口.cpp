/*
给你一个整数数组 `nums` 和一个整数 `k` ，找出三个长度为 `k` 、互不重叠、且 `3 * k` 项的和最大的子数组，并返回这三个子数组。

以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置（下标从 **0** 开始）。如果有多个结果，返回字典序最小的一个。
*/


class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
      // 记录3个滑动窗口的值
      int sum1 = 0, sum2 = 0, sum3 = 0;
      // 记录最大值
      int maxSum0 = 0, maxSum1 = 0, maxSum12 = 0, maxSum = 0;
      // 记录最大值所对应窗口的下标
      int idx[4];
      vector<int> ans;
      for (int i = 2 * k; i < nums.size(); i++) {
        // 每次i移动一个位置，然后改变3个滑动窗口的值
        sum1 += nums[i - 2*k];
        sum2 += nums[i - k];
        sum3 += nums[i];
        // 如果三个窗口的值，都可以取到，则开始维护最大值
        if (i >= 3*k - 1) {
          // 如果第一个窗口当前值，大于第一个窗口之前维护的最大值，则更新最大值并记录窗口下标
          if (sum1 > maxSum1) {
            idx[0] = i - 3*k + 1;
            maxSum1 = sum1;
          }
          // 如果第二个窗口当前值 + 第一个窗口最大值 大于之前维护的最大值，则更新最大值并记录窗口下标
          if (sum2 + maxSum1 > maxSum12) {
            idx[1] = idx[0];
            idx[2] = i - 2*k + 1;
            maxSum12 = sum2 + maxSum1;
          }
           // 如果第三个窗口当前值 + 前两个窗口最大值 大于之前维护的最大值，则更新最大值并记录窗口下标
          if (maxSum12 + sum3 > maxSum) {
            idx[3] = i - k + 1;
            maxSum = maxSum12 + sum3;
            ans = {idx[1], idx[2], idx[3]};
          }
          // 每次i移动一个位置，然后改变3个滑动窗口的值
          sum1 -= nums[i - 3*k + 1];
          sum2 -= nums[i - 2*k + 1];
          sum3 -= nums[i - k + 1];
        }
      }
      return ans;
    }
};



前言一：单个子数组的最大和
class Solution {
public:
    vector<int> maxSumOfOneSubarray(vector<int> &nums, int k) {
        vector<int> ans;
        int sum1 = 0, maxSum1 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum1 += nums[i];
            if (i >= k - 1) {
                if (sum1 > maxSum1) {
                    maxSum1 = sum1;
                    ans = {i - k + 1};
                }
                sum1 -= nums[i - k + 1];
            }
        }
        return ans;
    }
};

前言二：两个无重叠子数组的最大和
class Solution {
public:
    vector<int> maxSumOfTwoSubarrays(vector<int> &nums, int k) {
        vector<int> ans;
        int sum1 = 0, maxSum1 = 0, maxSum1Idx = 0;
        int sum2 = 0, maxSum12 = 0;
        for (int i = k; i < nums.size(); ++i) {
            sum1 += nums[i - k];
            sum2 += nums[i];
            if (i >= k * 2 - 1) {
                if (sum1 > maxSum1) {
                    maxSum1 = sum1;
                    maxSum1Idx = i - k * 2 + 1;
                }
                if (maxSum1 + sum2 > maxSum12) {
                    maxSum12 = maxSum1 + sum2;
                    ans = {maxSum1Idx, i - k + 1};
                }
                sum1 -= nums[i - k * 2 + 1];
                sum2 -= nums[i - k + 1];
            }
        }
        return ans;
    }
};