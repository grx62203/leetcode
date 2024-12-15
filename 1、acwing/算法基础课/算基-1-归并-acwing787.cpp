/*
给定你一个长度为 nn 的整数数列。

请你使用归并排序对这个数列按照从小到大进行排序。

并将排好序的数列按顺序输出。

输入格式
输入共两行，第一行包含整数 nn。

第二行包含 nn 个整数（所有整数均在 1∼1091∼109 范围内），表示整个数列。

输出格式
输出共一行，包含 nn 个整数，表示排好序的数列。

数据范围
1≤n≤100000
*/
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N], tmp[N];

void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;//判边界

    int mid = (l + r) >> 1;

    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

    //下面是双指针缝合两个有序数组为一个有序数组，相当于合并有序链表
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)//逐步缝合，先缝合小的元素
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];//尽量先缝补前部分
        else tmp[k ++ ] = q[j ++ ];
    //二选一执行
    while (i <= mid) tmp[k ++ ] = q[i ++ ];//左半边没有循环完的情况，全部接合
    while (j <= r) tmp[k ++ ] = q[j ++ ];  //右半边没有循环完的情况，全部接合
    
    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];//把结果拿回来
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    merge_sort(a, 0, n - 1);

    for (int i = 0; i < n; i ++ ) printf("%d ", a[i]);

    return 0;
}
