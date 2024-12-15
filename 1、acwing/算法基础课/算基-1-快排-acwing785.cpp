/*
给定你一个长度为 nn 的整数数列。

请你使用快速排序对这个数列按照从小到大进行排序。

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

const int N = 1e6 + 10;

int n;
int q[N];

/*
	当选择i的时候，不能选泽 x = q[l]，容易死循环，因为i是 l-1，可能是0
	int x = q[(l + r + 1) / 2], i = l - 1; j = r + 1;
	quick_sort(q,  l, i - 1 );
	quick_sort(q,  i, r);
*/
void quick_sort(int q[], int l, int r){
	if(l >= r) return;//判边界

	int x = q[l], i = l - 1, j = r + 1;
	while(i < j) //结束的时候前半部分小于等于x，后半部分大于等于x,
	{
	    do i ++; while(q[i] < x);
	    do j --; while(q[j] > x);
	    if(i < j) swap(q[i], q[j]);
	}
	//再进行递归对左右两半部分快排
	quick_sort(q,  l, j);
	quick_sort(q,  j + 1, r);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
	quick_sort(q, 0, n - 1);

	for (int i = 0; i < n; ++i) printf("%d", q[i]);
	return 0;
}
