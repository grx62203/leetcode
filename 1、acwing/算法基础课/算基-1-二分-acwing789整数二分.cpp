/*
给定一个按照升序排列的长度为 n 的整数数组，以及 q 个查询。

对于每个查询，返回一个元素 k 的起始位置和终止位置（位置从 0 开始计数）。

如果数组中不存在该元素，则返回 -1 -1。

输入格式
第一行包含整数 n 和 q，表示数组长度和询问个数。

第二行包含 n 个整数（均在 1∼10000 范围内），表示完整数组。

接下来 q 行，每行包含一个整数 kk，表示一个询问元素。

输出格式
共 q 行，每行包含两个整数，表示所求元素的起始位置和终止位置。

如果数组中不存在该元素，则返回 -1 -1。

数据范围
1≤n≤100000
1≤q≤10000
1≤k≤10000
*/
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int q[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

    while (m -- )//需要找m个目标
    {
        int x;
        scanf("%d", &x);

        //为了找到 大于等于x 的最小值
        int l = 0, r = n - 1;
        while (l < r)//二分结束的时候，l = r = 结果
        {
            int mid = l + r >> 1;
            if (q[mid] >= x) r = mid;
            else l = mid + 1;
        }

        if (q[l] != x) cout << "-1 -1" << endl;//二分结果不等于目标值，代表目标值不存在
        else
        {
            cout << l << ' ';//当前二分查找x，找的是右区间，也就是大于等于x 的最小值，所以想要范围从二分结果开始向右

            int l = 0, r = n - 1;
            //为了找到 小于等于x 的最大值，这里的 l 可以直接用刚才找到的 大于等于x的最小值
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (q[mid] <= x) l = mid;
                else r = mid - 1;
            }

            cout << l << endl;
        }
    }

    return 0;
}
