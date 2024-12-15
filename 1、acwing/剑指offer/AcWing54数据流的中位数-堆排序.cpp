/*
如何得到一个数据流中的中位数？

如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。

如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

数据范围
数据流中读入的数据总数 [1,1000]。

样例
输入：1, 2, 3, 4

输出：1,1.5,2,2.5

解释：每当数据流读入一个数据，就进行一次判断并输出当前的中位数。
*/

//大根堆存放多一个，先加到大根堆再调整
class Solution {
public:
	//大根堆存放小的集合，小根堆存放大的集合
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    void insert(int num){
    	//每次都先添加到大根堆，排序（大根堆要么多一个，要么一样）
        max_heap.push(num);
        //当大根堆top 大于 小根堆top时，交换使得排序正常（正常情况下大根堆top<小根堆top）
        while (min_heap.size() && min_heap.top() < max_heap.top())
        {
            auto minv = min_heap.top(), maxv = max_heap.top();
            min_heap.pop(), max_heap.pop();
            max_heap.push(minv), min_heap.push(maxv);
        }
        //如果大根堆的数量过多（一样或者多一个为正常，insert使大根堆数量总是多的），
        if (max_heap.size() > min_heap.size() + 1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    double getMedian(){
    	//大根堆的top存储奇数时中位数
        if (max_heap.size() + min_heap.size() & 1) return max_heap.top();
        return (max_heap.top() + min_heap.top()) / 2.0;
    }
};


//小根堆多存放一个，奇偶分类添加
//（添加后是奇数，先加到大根堆得到新top，将其弹出并加入到小根堆）==将新的数扔进去重新排序，得到新的<大根堆+小根堆>组合
//（添加后是偶数，先加到小根堆得到新top，将其弹出并加入到大根堆）==将新的数扔进去重新排序，得到新的<大根堆+小根堆>组合
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int> > maxheap;
    priority_queue<int, vector<int>, greater<int> > minheap;

    MedianFinder() {

    }
    
    void addNum(int num) {
    	//奇数时
        if(maxheap.size() == minheap.size()) {
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        //偶数时
        else {
            minheap.push(num);
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        int maxSize = maxheap.size(), minSize = minheap.size();
        int mid1 = maxheap.top(), mid2 = minheap.top();
        //如果是偶数个，返回top之平均
        //如果是奇数个，返回小根堆top（中位数）
        return maxSize == minSize ? ((mid1 + mid2) * 0.5) : mid2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
