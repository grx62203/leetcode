/*
每当下雨时，农夫约翰的田地总是被洪水淹没。

由于田地不是完全水平的，所以一些地方充满水后，留下了许多被水隔开的“岛”。

约翰的田地被描述为由 N 个连续高度值 H1,…,HN 指定的一维场景。

假设该场景被无限高的围墙包围着，请考虑暴雨期间发生的情况：

最低处首先被水覆盖，形成一些不连贯的岛，随着水位的不断上升，这些岛最终都会被覆盖。

一旦水位等于一块田地的高度，那块田地就被认为位于水下。

fig_islands.png

上图显示了一个示例：在左图中，我们只加入了刚好超过 1 单位的水，此时剩下 4 个岛（最大岛屿剩余数量），而在右图中，我们共加入了 7 单位的水，此时仅剩下 2 个岛。

请计算，暴风雨期间我们能在某个时间点看到的最大岛屿数量。

水会一直上升到所有田地都在水下。

输入格式
第一行包含整数 N。

接下来 N 行，每行包含一个整数表示 Hi。

输出格式
输出暴风雨期间我们能在某个时间点看到的最大岛屿数量。

数据范围
1≤N≤105,
1≤Hi≤109
*/
/*
一维差分+离散化
高度的数据范围比数量大的多
可以用map离散化，但不能用unordered_map，因为后者不能求前缀和
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

typedef long long LL;

using namespace std;
const int N = 100005,M = 1e9+1;//前者是数据范围、后者是高度
int a[N];
map<int ,int >b;//代替了差分中那个b数组，这是用来求前缀和得到真正a数组的每个元素的 值 的
int n;
int main()
{
    cin >> n;

    for (int i = 1; i <= n; i ++ ){
        cin >> a[i];
        if(a[i]>a[i-1]){
            //数的大小在[a[i-1],a[i]-1]之间的所有数大小都+1
            b[a[i-1]]++,b[a[i]]--;//代表某一段高度之间的水，会多一个小山，因为是前面是
            //如果前面是不严格降序，相邻小山之间有水，一定会多一个小山，都+1，直到水达到第二个小山高度的时候，这个多余小山的数量就没了
            //如果前面不是降序，前面的 前闭后开 范围 也会多一个小山，这样子 整个升序 都多一个小山，不冲突
        }
    }
    LL sum = 0 ,res = 0;
    for (auto i:b ){
        //求前缀和
        sum+=i.second;
        res = max(res,sum);
    }
    cout << res;
}
