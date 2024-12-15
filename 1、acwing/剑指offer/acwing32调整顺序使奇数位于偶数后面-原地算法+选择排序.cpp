/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序。

使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分。

数据范围
数组长度 [0,100]。
*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size() > 0)
            for(int i = 0; i < array.size() - 1; i++)
                for(int j = i + 1; j < array.size(); j++)
                    if(array[i] % 2 == 0 && array[j] % 2 == 1)
                        swap(array[i], array[j]);
    }
};


//拓展
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size() > 0)
            for(int i = 0; i < array.size() - 1; i++) {
                if(array[i] % 2 == 0)
                    for(int j = i + 1; j < array.size(); j++)
                        if(array[j] % 2 == 1)
                            swap(array[i], array[j]);
            }
    }
};
