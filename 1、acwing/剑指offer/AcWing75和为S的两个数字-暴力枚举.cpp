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
    vector<int> findNumbersWithSum(vector<int>& nums, int target) 
    {
        for(int i = 0; i < nums.size() - 1; i++)//i指向数对的第一个数字，从0到nums.size()-2
        {
            for(int j = nums.size() - 1; j > i; j--)//j指向数对的第二个数字，从nums.size()-1到i+1
            {

                if(nums[i] + nums[j] == target)//如果两数之和等于target
                    return vector<int>{nums[i], nums[j]};//返回数对
            }
        }
        return vector<int>{-1, -1};//穷举完没有答案，返回[-1,-1]
    }
};
