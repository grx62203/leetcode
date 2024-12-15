/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序。

使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分。

数据范围
数组长度 [0,100]。
*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
         vector<int> odd, even;
         for (int i = 0; i < array.size(); i ++)
         {
             if (array[i] % 2 == 1)
             {
                 odd.push_back(array[i]);
             }
             else
             {
                 even.push_back(array[i]);
             }
         }

         array.clear();

         for (int i = 0; i < odd.size(); i ++)     array.push_back(odd[i]);
         for (int i = 0; i < even.size(); i ++)   array.push_back(even[i]);

         return ;
    }
};



class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> res;
        for(int i=0;i<=1;i++)
            for(int j=0;j<array.size();j++)
                if(array[j]%2!=i) res.push_back(array[j]);
        array = res;
    }
};