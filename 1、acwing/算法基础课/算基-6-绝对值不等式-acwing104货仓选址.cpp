/*
在一条数轴上有 N 家商店，它们的坐标分别为 A1∼AN。

现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。

为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。

输入格式
第一行输入整数 N。

第二行 N 个整数 A1∼AN。

输出格式
输出一个整数，表示距离之和的最小值。

数据范围
1≤N≤100000,
0≤Ai≤40000
*/
/*
1、货舱建立在某个商店
2、二维曼哈顿距离，类似；二维欧几里得距离，随机算法求费马点
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int q[N];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

    sort(q, q + n);//从小到大

    int res = 0;
    //q[n / 2] 为选择的那个 奇数的中位数、偶数的中间较小的那一个    
    for (int i = 0; i < n; i ++ ) res += abs(q[i] - q[n / 2]);

    printf("%d\n", res);

    return 0;
}
