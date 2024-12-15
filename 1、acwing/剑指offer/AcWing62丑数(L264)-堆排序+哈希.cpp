/*
我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。

例如 6、8 都是丑数，但 14 不是，因为它包含质因子 7。

求第 n 个丑数的值。

数据范围
1≤n≤1000
样例
输入：5

输出：5
注意：习惯上我们把 1 当做第一个丑数。
*/
class Solution {
public:
    int getUglyNumber(int n) {
        unordered_set<int> se;
        priority_queue<int, vector<int>, greater<int>> minheap;

        se.insert(1);
        minheap.push(1);

        int cnt = 1;

        while(cnt < n)
        {
            int t = minheap.top();
            //弹出 n-1 个小的丑数，剩下的最小的就是第n个丑数
            minheap.pop();

            if(!se.count(t * 2))
            {
                se.insert(t * 2);
                minheap.push(t * 2);
            }

            if(!se.count(t * 3))
            {
                se.insert(t * 3);
                minheap.push(t * 3);
            }

            if(!se.count(t * 5))
            {
                se.insert(t * 5);
                minheap.push(t * 5);
            }

            cnt ++;
        }

        return minheap.top();
    }
};
