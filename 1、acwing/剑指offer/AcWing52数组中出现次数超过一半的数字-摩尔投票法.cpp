/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

假设数组非空，并且一定存在满足条件的数字。

思考题：

假设要求只能使用 O(n) 的时间和额外 O(1) 的空间，该怎么做呢？
数据范围
数组长度 [1,1000]。

样例
输入：[1,2,1,1,3]

输出：1
*/
//极端情况下，数量最大的可以和其他所有的两两抵消，最后剩下的就是数量最大的那个
//一般来说，抵消没有剩下就是数量不够多
//所以，数量少的两两抵消，不会影响结果
class Solution {
public:
    int moreThanHalfNum_Solution(vector<int>& nums) {
        int cnt = 0, val = -1;
        for (auto x : nums)
        	//如果如果当前数和val一样
        	//代表val多一个
            if (x == val)
                cnt ++ ;
            //如果当前数和val不一样
            //当val的cnt不为0时----互相抵消一个
            //当val的cnt为0时------代表所有前面的两两不同相抵消，重新选定val
            
            else
            {
                if (cnt) cnt -- ;
                else
                {
                    cnt = 1;
                    val = x;
                }
            }
        //最后剩下的胜者，肯定是数量大于数组一半数量的数
        return val;
    }
};


class Solution {
public:
    int moreThanHalfNum_Solution(vector<int>& nums) {
        int count = 1, val = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
        	//如果如果当前数和val一样
        	//代表val多一个
            if (nums[i] == val) count++;
            //如果当前数和val不一样
            //互相抵消一个
            else  count--;
            //当val的count == 0时------代表前面的所有两两不同相抵消，重新选定val
            if (count == 0) 
            { 
                val = nums[i];
                count = 1;
            }

        }
        //最后剩下的胜者，肯定是数量大于数组一半数量的数
        return val;
    }
};
