/*
给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，其中B中的元素B[i]=A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。

不能使用除法。

数据范围
输入数组长度 [0,20]。

样例
输入：[1, 2, 3, 4, 5]

输出：[120, 60, 40, 30, 24]
思考题：

能不能只使用常数空间？（除了输出的数组之外）
*/

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if (A.empty()) return vector<int>();
        int n = A.size();
        vector<int> res(n);
        res[0] = 1;
        //跳过o，因为没有左边
        for (int i = 1, p = A[0]; i < n; i ++ ) {
        	//求得每个新数组元素的左右乘积部分的 左边（正好利用一个p跳过了当前i对应的A[i]）
            res[i] = p;
            p *= A[i];
        }
        //跳过n-1，因为没有左右边        
        for (int i = n - 2, p = A[n - 1]; i >= 0; i -- ) {
        	//求得每个新数组元素的左右乘积部分的 右边（正好利用一个p跳过了当前i对应的A[i]）
            res[i] *= p;
            p *= A[i];
        }
        return res;
    }
};
