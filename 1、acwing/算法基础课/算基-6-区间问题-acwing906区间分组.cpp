/*
给定 N 个闭区间 [ai,bi]，请你将这些区间分成若干组，使得每组内部的区间两两之间（包括端点）没有交集，并使得组数尽可能小。

输出最小组数。

输入格式
第一行包含整数 N，表示区间数。

接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示最小组数。

数据范围
1≤N≤105,
−109≤ai≤bi≤109
*/
/*
1、按左端点从小到大排序
2、优化循环一次
    从前到后枚举每个区间
        判断能否将其放入某个现有的组中  L[I] <= Max_r
            不能---开一个新的组，放进去
            能-----将其放进去某组，且更新这个组的Max_r（随便放进一个组就可以）
3、暴力循环
    从前到后枚举每个区间若干次
        如果当前区间已经包含当前组的最后一个区间的右端点，pass
        否则，放入当前的组别
*/


#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n;

//自定义结构体与小于号
struct Range
{
    int l, r;
    bool operator< (const Range &W)const
    {
        return l < W.l;
    }
}range[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d%d", &range[i].l, &range[i].r);

    //从小到大排序，自定义小于号
    sort(range, range + n);
    
    //存储所有组的max_r就可以了，放在小根堆,每次拿出堆顶，也就是max_r最小的那个组来比较，结束的时候堆里面都是组的max_r
    priority_queue<int, vector<int>, greater<int>> heap;
    //枚举 左端点递增的所有区间
    for (int i = 0; i < n; i ++ )
    {
        auto r = range[i];
        //如果 堆空 或者 小堆顶 >= 当前区间的左端点---新开一个组
        if (heap.empty() || heap.top() >= r.l) heap.push(r.r);
        //否则---当前区间放入堆顶所在的组，弹出堆顶=将堆顶所在的组max_r更新为当前区间的右端点
        else
        {
            heap.pop();
            heap.push(r.r);
        }
    }
    
    printf("%d\n", heap.size());

    return 0;
}