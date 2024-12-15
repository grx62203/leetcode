/*
给定一个长度为 nn 的整数数列，以及一个整数 kk，请用快速选择算法求出数列从小到大排序后的第 kk 个数。

输入格式
第一行包含两个整数 nn 和 kk。

第二行包含 nn 个整数（所有整数均在 1∼1091∼109 范围内），表示整数数列。

输出格式
输出一个整数，表示数列的第 kk 小数。

数据范围
1≤n≤1000001≤n≤100000,
1≤k≤n
*/

/*
快速排序选择
找第k个数
第一次找一个值x，递归排序的得到  左边严格小于等于x，右边严格大于等于x
当判断第k个数位于 左半部分的时候，就只要递归排序左半部分就好了，依次按照这样的规则优化
*/

#include <iostream>

using namespace std;

const int N = 100010;

int q[N];

/*  
    快排核心
	int i = l - 1, j = r + 1, x = q[l];
	while(i < j)
	{
		while(q[++ i] < x);
		while(q[-- j] > x);
		if(i < j) swap(q[i], q[j]);
	} 
*/

int quick_sort(int q[], int l, int r, int k)
{
    //2、处理边界，返回答案
    if (l >= r) return q[l];
    //3、快排模板标准-同时处理左右两边
    int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
    while (i < j)//从两边向中间搜索，将大的放后面，小的放前面
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    //4、左半边有 j-l+1 个数
    if (j - l + 1 >= k) return quick_sort(q, l, j, k);
    //5、k - (j - l + 1) 代表以及找到了前  j-l+1个数，还需要这么多
    else return quick_sort(q, j + 1, r, k - (j - l + 1));
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    //1、输入n个数
    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]); 

    cout << quick_sort(q, 0, n - 1, k) << endl;

    return 0;
}
