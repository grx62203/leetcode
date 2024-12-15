/*
给定两个升序排序的有序数组 A 和 B，以及一个目标值 x。

数组下标从 0 开始。

请你求出满足 A[i]+B[j]=x的数对 (i,j)

数据保证有唯一解。

输入格式
第一行包含三个整数 n,m,x，分别表示 A 的长度，B 的长度以及目标值 x。

第二行包含 n 个整数，表示数组 A。

第三行包含 m 个整数，表示数组 B。

输出格式
共一行，包含两个整数 i 和 j。

数据范围
数组长度不超过 105
同一数组内元素各不相同。
1≤数组元素≤109
*/

/*
双指针-凑target
对两有序数组之元素进行凑目标和
*/
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m, x;
int a[N], b[N];

int main()
{
    scanf("%d%d%d", &n, &m, &x);//两个数组是升序排序的
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    for (int i = 0; i < m; i ++ ) scanf("%d", &b[i]);
    //i指向第一个数组的第一个，j 指向第二个数组的最后一个元素
    for (int i = 0, j = m - 1; i < n; i ++ )
    {
    	//i不变的时候，单纯移动 j ，判断目标和，满足的时候推出while
        while (j >= 0 && a[i] + b[j] > x) j -- ;
        if (j >= 0 && a[i] + b[j] == x) cout << i << ' ' << j << endl;
    }

    return 0;
}