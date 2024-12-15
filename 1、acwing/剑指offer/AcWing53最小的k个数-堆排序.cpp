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
//y总-k=0会报错
class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int> heap;
        for (auto x : input)
        {
        	//这里为什么当size=k的时候，不添加，可能就是k=0报错的原因
            if (heap.size() < k || heap.top() > x) heap.push(x);
            if (heap.size() > k) heap.pop();
        }
        vector<int> res;
        while (heap.size()) res.push_back(heap.top()), heap.pop();
        reverse(res.begin(), res.end());
        return res;
    }
};

//k=0不会报错
class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        //默认大根堆
        priority_queue<int> heap;
        for(auto x : input)
        {
            heap.push(x);
            //将多余的大值pop
            if(heap.size() > k) heap.pop(); 
        }
        while(heap.size())
        {
            res.push_back(heap.top());
            heap.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};