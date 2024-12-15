/*
给定 N 个闭区间 [ai,bi] 以及一个线段区间 [s,t]，请你选择尽量少的区间，将指定线段区间完全覆盖。

输出最少区间数，如果无法完全覆盖则输出 −1。

输入格式
第一行包含两个整数 s 和 t，表示给定线段区间的两个端点。

第二行包含整数 N，表示给定区间数。

接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示所需最少区间数。

如果无解，则输出 −1。

数据范围
1≤N≤105,
−109≤ai≤bi≤109,
−109≤s≤t≤109
*/
/*
1、按左端点从小到大排序
2、从前往后枚举每个区间，此时初始化 start(线段区间左) 
    在所有能覆盖 start 的所有区间中，选择右端点最大的一个区间，区间计数+1
    选完之后将 start 更新为选择的第一个区间的右端点
    当 start > end 的时候，结束
*/
/*
当进行区间与区间的重叠判别，排序右端点
当进行区间处理得到更大的区间，排序左端点
*/



#include <iostream>
#include <algorithm>

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
    int st, ed;
    scanf("%d%d", &st, &ed);
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d%d", &range[i].l, &range[i].r);

    //从小到大排序，自定义小于号
    sort(range, range + n);

    int res = 0;//选择区间的数量
    bool success = false;
    //枚举 左端点递增的所有区间
    for (int i = 0; i < n; i ++ )
    {
        int j = i, r = -2e9;
        //从i开始枚举 所有左端点 < start 的区间，选择右端点最大的一个，更新 r 为  右端点
        //此次 所有被枚举过的区间 会跳过，下一个大循环从 j 开始
        while (j < n && range[j].l <= st)
        {
            r = max(r, range[j].r);
            j ++ ;
        }
        //如果被选择的区间的右端点 <  start --- 没有找到方案或者方案失败，res=-1，break
        if (r < st)
        {
            res = -1;
            break;
        }
        //如果被选择的区间的右端点 >= start --- 方案开始或者继续，区间数 res += 1
        res ++ ;
        //如果被选择的区间的右端点 >=  end  --- 方案结束       ，成功标记，break
        if (r >= ed)
        {
            success = true;
            break;
        }
        //更新start = 选择区间的右端点
        st = r;
        //此时 j 表示没有没有被枚举过的最小的区间，为了平衡 i ++ ，使下一次循环
        i = j - 1;
    }

    if (!success) res = -1;
    printf("%d\n", res);

    return 0;
}
