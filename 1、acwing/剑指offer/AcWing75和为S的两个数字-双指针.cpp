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

class Solution {
public:

    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        for(int i = 0 ,j = nums.size() - 1; i <j;){
            if(nums[i] +nums[j] == target)
               return  vector<int>{nums[i],nums[j]};
            else if(nums[i] + nums[j] < target)
                i++;
            else 
                j--;
        }
    }
};

//leetcode
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0; int r = nums.size() - 1;
        while (l < r) {
            if (target == nums[l] + nums[r]) {
                return vector<int>{nums[l], nums[r]};
            }
            else if (target > nums[l] + nums[r]) {    
                l++;
            }
            else if (target < nums[l] + nums[r]) {    
                r--;
            }
        }
        return vector<int>();
    }
};