/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序。

使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分。

数据范围
数组长度 [0,100]。
*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int l = 0, r = array.size() - 1;
        while (l < r) {
            while (l < r && array[l] % 2 == 1) l ++ ;
            while (l < r && array[r] % 2 == 0) r -- ;
            if (l < r) swap(array[l], array[r]);
        }
    }
};
