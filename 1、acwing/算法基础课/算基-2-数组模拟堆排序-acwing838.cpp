/*
输入一个长度为 nn 的整数数列，从小到大输出前 mm 小的数。

输入格式
第一行包含整数 nn 和 mm。

第二行包含 nn 个整数，表示整数数列。

输出格式
共一行，包含 mm 个整数，表示整数数列中前 mm 小的数。

数据范围
1≤m≤n≤1051≤m≤n≤105，
1≤数列中元素≤109
*/
/*
数组模拟堆排序
建立小根堆，依次从小到大输出堆的前m个值
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], cnt;
//数组建 堆的模板，小根堆的操作，让大的值尽可能向下走，走到下面没有更小的值为止
void down(int u)
{
    int t = u;
    //如果左儿子存在，且左儿子的值小于父亲，选择左儿子
    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    //如果右儿子存在，且右儿子的值小于父亲，选择右儿子
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    //如果进行了选择，交换父亲与选中的儿子，且对选中的儿子进行下一次down
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]);
    cnt = n;

    for (int i = n / 2; i; i -- ) down(i);//数组建 堆的模板

    while (m -- )
    {
        printf("%d ", h[1]);
        h[1] = h[cnt -- ];//删除堆的最小值，用最后一个值代替，同时计数-1
        down(1);          //将最后一个值往下找到应该去的位置，最后第一个就更新为当前堆的最小值了
    }

    puts("");

    return 0;
}