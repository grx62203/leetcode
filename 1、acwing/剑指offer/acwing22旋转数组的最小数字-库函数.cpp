/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。

输入一个升序的数组的一个旋转，输出旋转数组的最小元素。

例如数组 {3,4,5,1,2} 为 {1,2,3,4,5} 的一个旋转，该数组的最小值为 1。

数组可能包含重复项。

注意：数组内所含元素非负，若数组大小为 0，请返回 −1。

数据范围
数组长度 [0,90]。
*/
//时间：O（n）
class Solution {
public:
    int findMin(vector<int>& nums) {
        return nums.empty() ? -1 : *min_element(nums.begin(),nums.end());
    }
};
