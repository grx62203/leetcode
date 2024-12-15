/*
输入一个长度为 n 的整数序列。

接下来输入 m个操作，每个操作包含三个整数 l,r,c，表示将序列中 [l,r] 之间的每个数加上 c。

请你输出进行完所有操作后的序列。

输入格式
第一行包含两个整数 n 和 m。

第二行包含 n 个整数，表示整数序列。

接下来 m 行，每行包含三个整数 l，r，c，表示一个操作。

输出格式
共一行，包含 n 个整数，表示最终序列。

数据范围
1≤n,m≤100000
1≤l≤r≤n
−1000≤c≤1000
−1000≤整数序列中元素的值≤1000
*/
#include <iostream>
using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];//a是b的前缀和，b是a的差分

void insert(int l, int r, int c)
{
    b[l] += c;    //保证在 l 之后的每一位都 + 1
    b[r + 1] -= c;//保证在 r 之后的 每一位都避免 + 1 操作
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    
    //第一次差分构造之后，b数组中前n项的和就是a[n] 
    for (int i = 1; i <= n; i ++ ) insert(i, i, a[i]);//初始化b数组操作=将a的值先构造差分
       

    while (m -- )//m次询问
    {
        int l, r, c;//l r 是闭区间，c是需要增加的量
        scanf("%d%d%d", &l, &r, &c);
        //第二次差分构造之后，b数组中前n项的和就是假设增加成功的新a[n]
        insert(l, r, c);                              //改造b数组操作=用增加量构造差分
        
    }

    //这个过程之后b数组就变成了 增加成功的 新 a数组
    for (int i = 1; i <= n; i ++ ) b[i] += b[i - 1];//利用b数组求其前缀和来构造新a数组的过程
    
    for (int i = 1; i <= n; i ++ ) printf("%d ", b[i]);//将新a数组输出

    return 0;
}