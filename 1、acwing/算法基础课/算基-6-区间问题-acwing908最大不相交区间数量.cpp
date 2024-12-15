/*
给定 N 个闭区间 [ai,bi]，请你在数轴上选择若干区间，使得选中的区间之间互不相交（包括端点）。

输出可选取区间的最大数量。

输入格式
第一行包含整数 N，表示区间数。

接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示可选取区间的最大数量。

数据范围
1≤N≤105,
−109≤ai≤bi≤109
*/
/*
1、就是选课，不相交，下一节课的左端点必须大于前一节课的右端点
2、按右端点从小到大排序
3、从前到后枚举每个区间
    如果当前区间已经包含了上一个选择区间的右端点，pass
    否则，选择当前区间
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
        return r < W.r;
    }
}range[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d%d", &range[i].l, &range[i].r);

    //从小到大排序，自定义小于号
    sort(range, range + n);

    int res = 0, ed = -2e9;//选择区间的数量、上一个选择的区间的右端点的值
    //枚举 右端点递增的所有区间
    for (int i = 0; i < n; i ++ )
        //如果 当前区间的 左端点 > 上一个选择的区间的右端点（标记区间的右端点）
        //---区间数+1、选择标记ed=当前区间的右端点
        if (range[i].l > ed)
        {
            res ++ ;
            ed = range[i].r;
        }

    printf("%d\n", res);

    return 0;
}
