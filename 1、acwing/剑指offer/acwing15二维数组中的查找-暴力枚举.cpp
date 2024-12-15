/*
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。

请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

数据范围
二维数组中元素个数范围 [0,1000]
*/
/*
时间复杂度:n*n
*/
//wwb
class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        for (int i = 0; i < array.size(); i ++)
        {
            for (int j = 0; j < array[i].size(); j ++)
            {
                if (array[i][j] == target)   return true;
            }
        }

        return false;
    }
};