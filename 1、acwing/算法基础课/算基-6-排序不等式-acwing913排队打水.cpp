/*
有 n 个人排队到 1 个水龙头处打水，第 i 个人装满水桶所需的时间是 ti，请问如何安排他们的打水顺序才能使所有人的等待时间之和最小？

输入格式
第一行包含整数 n。

第二行包含 n 个整数，其中第 i 个整数表示第 i 个人装满水桶所花费的时间 ti。

输出格式
输出一个整数，表示最小的等待时间之和。

数据范围
1≤n≤105,
1≤ti≤104
*/
/*
1、最墨迹的最后打水
2、总时间t = 第一个同学时间t1*被等次数n-1 + 第二个同学时间t2*被等次数n-2 + 
3、从小到大的顺序排队，总时间最小
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
int t[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &t[i]);

    sort(t, t + n);   //从小到大
    reverse(t, t + n);//从大到小

    LL res = 0;
    //t = 最大的t1*0 + 第二大的t2*1 + 第三大的t3*2+++++
    for (int i = 0; i < n; i ++ ) res += t[i] * i;
    //for (int i = 0; i < n; i ++ ) res += t[i] * (n - i - 1);---没有reverse

    printf("%lld\n", res);

    return 0;
}
