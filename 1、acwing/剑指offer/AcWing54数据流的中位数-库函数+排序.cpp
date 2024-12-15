/*
如何得到一个数据流中的中位数？

如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。

如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

数据范围
数据流中读入的数据总数 [1,1000]。

样例
输入：1, 2, 3, 4

输出：1,1.5,2,2.5

解释：每当数据流读入一个数据，就进行一次判断并输出当前的中位数。
*/
class Solution {
public:
    vector<int> nums;
    void insert(int num){
        nums.push_back(num);
    }

    double getMedian(){
        int len = nums.size();
        int mid = len / 2;
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        if(len % 2 == 0)    //偶数
            return ((double)tmp[mid]+(double)tmp[mid-1]) / 2;//别让自动转化为整数了
        else
            return tmp[mid];
    }
};
