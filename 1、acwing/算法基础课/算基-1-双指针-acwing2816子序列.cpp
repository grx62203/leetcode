/*
给定一个长度为 n 的整数序列 a1,a2,…,an 以及一个长度为 m 的整数序列 b1,b2,…,bm

请你判断 a 序列是否为 b 序列的子序列。

子序列指序列的一部分项按原有次序排列而得的序列，例如序列 {a1,a3,a5} 是序列 {a1,a2,a3,a4,a5} 的一个子序列。

输入格式
第一行包含两个整数 n,m

第二行包含 n 个整数，表示 a1,a2,…,an

第三行包含 m 个整数，表示 b1,b2,…,bm

输出格式
如果 a 序列是 b 序列的子序列，输出一行 Yes。

否则，输出 No。

数据范围
1≤n≤m≤105
−109≤ai,bi≤109
*/

/*
双指针-子序列
对两有序数组进行判断子序列
*/
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    for (int i = 0; i < m; i ++ ) scanf("%d", &b[i]);

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j]) i ++ ;
        j ++ ;//不相同的时候，递进 数组b 的下一个元素， 因为都是有次序排序的
    }

    if (i == n) puts("Yes");// i 表示出现相同 元素的 个数， 等于数组a的长度时 yes
    else puts("No");

    return 0;
}