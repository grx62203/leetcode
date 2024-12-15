/*
输入一个数组和一个数字 s，在数组中查找两个数，使得它们的和正好是 s。

如果有多对数字的和等于 s，输出任意一对即可。

你可以认为每组输入中都至少含有一组满足条件的输出。

数据范围
数组长度 [1,1002]。

样例
输入：[1,2,3,4] , sum=7

输出：[3,4]
*/

//leetcode
class Solution {
public:
    bool Check(const vector<int>& v, int idx, int find) {
        return v[idx] >= find;
    }

    bool bSearch(const vector<int>& v, int l, int r, int find)
    {
        bool ret = false;
        if (l < 0 || l >= v.size() || r < 0 || r >= v.size()) return ret;

        while (l < r) {
            int mid = l+r >> 1;
            if (Check(v,mid,find)) r = mid;
            else l = mid + 1;
        }

        return v[l] == find;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int find = target - nums[i];
            bool ret = false;
            if (find > nums[i]) {
                ret = bSearch(nums,i+1,nums.size()-1,find);
                if (ret) {
                    return vector<int>{nums[i], find};
                }
            }
            else if (find < nums[i]) {
                ret = bSearch(nums, 0, i - 1, find);
                if (ret) {
                    return vector<int>{nums[i], find};
                }
            }
            else {
                //说明查找的数字和nums[i]相等 直接查找该数字前后是否有该数即可
                if (i - 1 >= 0 && nums[i - 1] == nums[i]) return vector<int>{find, find};
                if (i + 1 < nums.size() && nums[i + 1] == nums[i]) return vector<int>{find, find};
            }
        }

        return vector<int>();
    }
};
