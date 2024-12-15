/*
维护一个集合，支持如下几种操作：

I x，插入一个数 xx；
Q x，询问数 xx 是否在集合中出现过；
现在要进行 NN 次操作，对于每个询问操作输出对应的结果。

输入格式
第一行包含整数 NN，表示操作数量。

接下来 NN 行，每行包含一个操作指令，操作指令为 I x，Q x 中的一种。

输出格式
对于每个询问指令 Q x，输出一个询问结果，如果 xx 在集合中出现过，则输出 Yes，否则输出 No。

每个结果占一行。

数据范围
1≤N≤1051≤N≤105
−109≤x≤109
*/
/*
哈希散列表开放寻址法
*/
#include <cstring>
#include <iostream>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;//N更新为两倍以上的第一个质数

int h[N];//只用一个数组存储
//找到x的位置或者x应该放的位置
int find(int x)
{
    int t = (x % N + N) % N;//哈希值
    //当找到一个坑位 等于null 或者 等于x的时候，这个位置就被返回
    while (h[t] != null && h[t] != x)
    {
        t ++ ;
        if (t == N) t = 0;//是个循环，链接尾首
    }
    return t;
}

int main()
{
    memset(h, 0x3f, sizeof h);//memset是以字节为单位

    int n;
    scanf("%d", &n);

    while (n -- )
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);         //识别命令行
        if (*op == 'I') h[find(x)] = x;//1、插入一个数
        else                           //2、判断这个数是否存在
        {
            if (h[find(x)] == null) puts("No");
            else puts("Yes");
        }
    }

    return 0;
}