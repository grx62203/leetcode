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
        vector<int>left(A.size(),1);
        vector<int>right(A.size(),1);
        for(int i = 1;i<A.size();i++){
            left[i] = A[i-1]*left[i-1];
        }
        for(int i = A.size()-2;i>=0;i--){
            right[i] = A[i+1]*right[i+1];
        }
        vector<int>B(A.size(),0);
        for(int i = 0;i<A.size();i++){
            B[i] = left[i]*right[i];
        }
        return B;
    }
};
