/*
这里有 `n` 门不同的在线课程，按从 `1` 到 `n` 编号。给你一个数组 `courses` ，
其中 `courses[i] = [durationi, lastDayi]` 表示第 `i` 门课将会 **持续** 上 `durationi` 天课，
并且必须在不晚于 `lastDayi` 的时候完成。

你的学期从第 `1` 天开始。且不能同时修读两门及两门以上的课程。

返回你最多可以修读的课程数目。
*/
==因此某一段特定的时间轴上，问题可抽象成有条件限制的组合优化问题。==

1、==由于数据范围为 10^4104，泛化背包做法需要记录的维度大于一维，不予考虑。==

2、==再然后容易想到「二分」，显然在以最大选择数量 ans为分割点的数组上具有「二段性」：==

- 使用数量小于等于 ans 的课程能够构造出合法排序（考虑在最长合法序列上做减法即可）；
- 使用数量大于 ans 的课程无法构造出合法排列

此时二分范围为 [0, n]
问题转化为：如何在 O(n) 检查是否可构造出某个长度 len 的合法排列（实现 `check` 方法）。

==**常规的线性扫描做法无法确定是否存在某个长度的合法排列，因此二分不予考虑。**==

我们需要运用「贪心」思维考虑可能的方案

class Solution {
public:
    /*另外一种sort的规则
    static bool cmp(vector<int> &x, vector<int> &y) {
        return x[1] < y[1];
    }
    sort(courses.begin(), courses.end(), cmp);
    */
    
    int scheduleCourse(vector<vector<int>>& courses) {
    	sort(courses.begin(), courses.end(), [](const auto& c0, const auto& c1){
            return c0[1] < c1[1];
        });// 首先我们按课程结束时间升序排列, 我们总是首先考虑当前最先结束的课程
        
        priority_queue<int> q;      //优先队列的课程总时间
        int total = 0;
        
        for(const auto& c : courses){
            int ti = c[0], di = c[1];
            if(total + ti <= di){// 如果这门课可以顺利的在课程的有效期内学完, 那么我们就放心的学
                total += ti;
                q.push(ti);
            }
            else if(!q.empty() && q.top() > ti){// 如果这门课不能再课程的有效期内学完 且 之前有所需的时间更多的课, 替换掉
                total -= q.top() -ti;
                q.pop();
                q.push(ti);
            }
        }
        
        return q.size();
    }
};