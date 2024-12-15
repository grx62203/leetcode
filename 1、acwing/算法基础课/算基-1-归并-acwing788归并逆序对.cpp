/*
给定一个长度为 n 的整数数列，请你计算数列中的逆序对的数量。

逆序对的定义如下：对于数列的第 i 个和第 j 个元素，如果满足 i<j 且 a[i]>a[j]，则其为一个逆序对；否则不是。

输入格式
第一行包含整数 n，表示数列的长度。

第二行包含 n 个整数，表示整个数列。

输出格式
输出一个整数，表示逆序对的个数。

数据范围
1≤n≤1000001≤n≤100000，
数列中的元素的取值范围 [1,109][1,109]。
*/

/*
归并排序
递归排序左右两边
逆序对分类
	一、同时左半边
	二、同时右半边
	三、一左一右
解决办法
	一、 merge_sort(L,mid)
	二、 merge_sort(R,mid)
	三、依次遍历right的元素，求left中大于 此元素的数量 n
技巧
	情况三合并链表的时候，对于第二条链表中的某一个元素j而言，当发现了第一条链表中第一个大于j的元素i的时候
	n = mid - i + 1
    前两情况就是通过下一次以及以后的merge_sort中的n 来解决 

*/
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int a[N], tmp[N];

LL merge_sort(int q[], int l, int r)
{
    if (l >= r) return 0;

    int mid = (l + r) >> 1;

    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

    //归并核心
    //下面是双指针缝合两个有序数组为一个有序数组，相当于合并有序链表
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else
        {
            res += mid - i + 1;//唯一多出来的一个部分，为了记录逆序对的数量。每一次相加都代表此时对后一条链表的每个数而言的逆序对的数量
            tmp[k ++ ] = q[j ++ ];
        }
    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    //物归原主
    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];

    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    cout << merge_sort(a, 0, n - 1) << endl;

    return 0;
}
