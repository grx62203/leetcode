/*
给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。

输入格式
第一行包含整数 N。

第二行包含 N 个整数，表示完整序列。

输出格式
输出一个整数，表示最大长度。

数据范围
1≤N≤100000，
−109≤数列中的数≤109
*/
//数据范围更大



#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N];
int f[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    int len = 0;
    //遍历每一个数组元素
    for (int i = 0; i < n; i ++ )
    {
        //找到第一个 >= a[i] 的f[]中的元素下标
        int l = 0, r = len;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (f[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);//f[]长度为 f[]原长度 与 第一个>=的下标+1 的较大值
        f[r + 1] = a[i];      //用 a[i] 替换掉第一个 >= a[i]  的f[]中的元素，可能是原来序列中替换，可能是添加原序列的新元素
        //n次替换后
            //f[]中是字典序最大的序列
            //len是f[]的被操作过的元素长度
    }

    printf("%d\n", len);

    return 0;
}

/*************************************************************************************/
思路一：
ps1：
首先数组a中存输入的数（原本的数），开辟一个数组f用来存结果，最终数组f的长度就是最终的答案；
假如数组f现在存了数，当到了数组a的第i个位置时，首先判断a[i] > f[cnt] ？ 
若a[i] >  f[cnt] 则直接将这个数添加到数组f中，即f[++cnt] = a[i];这个操作时显然的。
当a[i] <= f[cnt] 时,我们就用a[i]去替代数组f中的第一个大于等于a[i]的数，
    因为在整个过程中我们维护的数组f 是一个递增的数组，所以我们可以用二分查找在 logn 的时间复杂的的情况下直接找到对应的位置，然后替换，
    即f[l] = a[i]。

我们用a[i]去替代f[i]的含义是：以a[i]为最后一个数的严格单调递增序列,这个序列中数的个数为l个。
这样当我们遍历完整个数组a后就可以得到最终的结果。

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;

int a[maxn], f[maxn];
int cnt;

inline int find(int x) {
    int l = 1, r = cnt; 
    while(l < r) {
        int mid = l + r >> 1;
        if(f[mid] >= x) r = mid;
        else l = mid + 1;
    }

    return l;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);

    f[++cnt] = a[1];
    for(int i = 2; i <= n; i ++) 
        if(a[i] > f[cnt]) f[ ++ cnt] = a[i];
        else {
            int tmp = find(a[i]);
            f[tmp] = a[i]; 
        }

    printf("%d\n", cnt);

    return 0;
}