/*
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。

请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

数据范围
二维数组中元素个数范围 [0,1000]
*/
/*
核心在于发现每个子矩阵右上角的数的性质：
如下图所示，x左边的数都小于等于x，x下边的数都大于等于x。
假设当前枚举的数是 xx：
	如果 xx 等于target，则说明我们找到了目标值，返回true；
	如果 xx 小于target，则 xx 左边的数一定都小于target，我们可以直接排除当前一整行的数；
	如果 xx 大于target，则 xx 下边的数一定都大于target，我们可以直接排序当前一整列的数；

时间: O(n+m)
*/
//右上角开始
class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        if (array.empty() || array[0].empty()) return false;
        int i = 0, j = array[0].size() - 1;
        while (i < array.size() && j >= 0) {
            if (array[i][j] == target) return true;
            if (array[i][j] > target) j -- ;
            else i ++ ;
        }
        return false;
    }
};

//左下角开始
class Solution {
public:
    bool searchArray(vector<vector<int>> A, int target) {
        if(A.empty() || A[0].empty()) return false;
        int i = A.size() - 1, j = 0;
        while(i >= 0 && j < A[0].size())
        {
            if(A[i][j] == target) return true;
            if(A[i][j] > target) i --;
            else j ++;
        }

        return false;
    }
};