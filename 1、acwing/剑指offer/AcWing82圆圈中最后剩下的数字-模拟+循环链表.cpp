/*
0,1,…,n−1 这 n 个数字 (n>0) 排成一个圆圈，从数字 0 开始每次从这个圆圈里删除第 m 个数字。

求出这个圆圈里剩下的最后一个数字。

数据范围
1≤n,m≤4000
样例
输入：n=5 , m=3

输出：3
*/
//list可以模拟循环
#include <list>
class Solution {
public:
    int lastRemaining(int n, int m){
        list<int> nums;
        for (int i = 0; i < n; ++i) nums.push_back(i);
        auto it = nums.begin();
        int k = m - 1;
        while (nums.size() > 1){
            while (k--){
                it++;
                if (it == nums.end()) it = nums.begin();//别迭代器移到开头实现模拟环形列表
            }
            it = nums.erase(it);//删除第m个元素
            if (it == nums.end()) it = nums.begin();
            k = m - 1;
        }
        return nums.front();
    }
};

//数组一直不变，但t一直延长，最后算%n
//数组中n个元素哦那个res判别在不在
class Solution {
public:
    int lastRemaining(int n, int m) {
        if(n == 1) return 0; // 特判
        vector<bool> res(n, true); //用数组来模拟枪毙过程
        int t = m - 1, s = 1; 
        while(s ++ < n) { //模拟n-1次，每次枪毙一个数
            res[t % n] = false; //枪毙！标记该位
            int k = m;
            while(k) { //在还活着的数当中向后数第m个
                t ++ ;
                if(res[t % n] == true) k -- ;
            }
        }
        return t % n;
    }
};


//leetcode,java
class Solution {
    public int lastRemaining(int n, int m) {
        List<Integer> list = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            list.add(i);
        }
        int start = 0;
        int index = 0;
        while (list.size() > 1) {
            int len = list.size();
            index = (start + m - 1) % len;
            list.remove(index);
            start = index;
        }
        return list.get(0);
    }
}