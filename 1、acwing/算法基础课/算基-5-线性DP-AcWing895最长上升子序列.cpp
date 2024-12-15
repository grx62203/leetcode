/*
给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。

输入格式
第一行包含整数 N。

第二行包含 N 个整数，表示完整序列。

输出格式
输出一个整数，表示最大长度。

数据范围
1≤N≤1000，
−109≤数列中的数≤109
*/
/*
0、DP
    状态表示 f[i] 
        集合   
            所有 终点为 i 的子序列 长度最大值
            条件 （数目限制、体积限制）
                 终点是 i
        属性   
            最大值
            (最小值)
            (数量)
    状态计算
        本质就是集合的划分
        f[i] = max(f[i], f[j] + 1);----------for (int j = 1; j < i; j ++ )遍历所有在 i 前的位置，  if (a[j] < a[i])
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

    //遍历所有位置
    for (int i = 1; i <= n; i ++ )
    {
        f[i] = 1; // 只有a[i]一个数
        for (int j = 1; j < i; j ++ )//遍历所有在 i 前的位置
            if (a[j] < a[i])    f[i] = max(f[i], f[j] + 1);
    }
    
    //在所有位置的子序列长度最大值 中找 max
    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = max(res, f[i]);

    printf("%d\n", res);

    return 0;

    /*ps1：从后往前找，找到的就是字典序最小的序列
    vector<int> ans(res);
    for (int i = n, j = res; j > 0; i -- ) {
        if (f[i] == j)   res[ -- j] = a[i];
    }
    return ans;    
    */
}