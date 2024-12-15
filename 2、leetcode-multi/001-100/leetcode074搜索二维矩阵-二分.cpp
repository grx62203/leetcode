/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。

*/
//一次二分-右区间的左边界
//若将矩阵每一行拼接在上一行的末尾，则会得到一个升序数组，我们可以在该数组上二分找到目标元素。
//代码实现时，可以二分升序数组的下标，将其映射到原矩阵的行和列上。
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int n = matrix.size(), m = matrix[0].size();

        int l = 0, r = n * m - 1;
        while (l < r) {
            int mid = l + r >> 1;
            // matrix[mid / m][mid % m] ,求出mid所在行数，mid所在列数，得到mid的位置，前行后列
            if (matrix[mid / m][mid % m] >= target) r = mid;
            else l = mid + 1;
        }
        return matrix[r / m][r % m] == target;
    }
};


//两次二分
//由于每行的第一个元素大于前一行的最后一个元素，且每行元素是升序的，所以每行的第一个元素大于前一行的第一个元素，因此矩阵第一列的元素是升序的。
//我们可以对矩阵的第一列的元素二分查找，找到最后一个不大于目标值的元素，然后在该元素所在行中二分查找目标值是否存在
class Solution {
public:
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        //找到target所在的那一行的下一行
        //查找[first, last)区域中第一个大于 val 的元素。
        //查找[first, last)区域中第一个不符合 comp 规则的元素-----------------也就target所在行的下一行
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int> &a) {
            return b < a[0];
        });
        //说明target在第一行之前
        if (row == matrix.begin()) {
            return false;
        }
        --row;
        //查找target是否存在
        return binary_search(row->begin(), row->end(), target);
    }
};
