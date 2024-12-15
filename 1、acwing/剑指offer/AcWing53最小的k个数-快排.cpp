/*
输入 n 个整数，找出其中最小的 k 个数。

注意：

输出数组内元素请按从小到大顺序排序;
数据范围
1≤k≤n≤1000
样例
输入：[1,2,3,4,5,6,7,8] , k=4

输出：[1,2,3,4]
*/
class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        for(int i = 1;i <= k;i++)
            res.push_back(quick_select(input,0,input.size()-1,i));
        return res;
    }

    int quick_select(vector<int>& q,int l,int r,int k)
    {
        if(l >= r) return q[l];
        int i = l-1,j = r+1,x = q[l+r >> 1];
        while(i < j)
        {
            do i++;while(q[i] < x);
            do j--;while(q[j] > x);
            if(i < j) swap(q[i],q[j]);
        }
        if(k <= j-l+1) return quick_select(q,l,j,k);
        else return quick_select(q,j+1,r,k-(j-l+1));
    }

};
