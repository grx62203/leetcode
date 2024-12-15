/*
维护一个集合，初始时集合为空，支持如下几种操作：

I x，插入一个数 xx；
PM，输出当前集合中的最小值；
DM，删除当前集合中的最小值（数据保证此时的最小值唯一）；
D k，删除第 kk 个插入的数；
C k x，修改第 kk 个插入的数，将其变为 xx；
现在要进行 NN 次操作，对于所有第 22 个操作，输出当前集合的最小值。

输入格式
第一行包含整数 NN。

接下来 NN 行，每行包含一个操作指令，操作指令为 I x，PM，DM，D k 或 C k x 中的一种。

输出格式
对于每个输出指令 PM，输出一个结果，表示当前集合中的最小值。

每个结果占一行。

数据范围
1≤N≤1051≤N≤105
−109≤x≤109−109≤x≤109
数据保证合法。
*/
/*
数组模拟映射堆
*/
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 100010;

int h[N], ph[N], hp[N], cnt;//ph存储对应第N个插入的数在h中的下标、hp存储这h中的下标N对应的是第几个插入的
//ph[k] = i;
//hp[i] = k;

//重写了交换，不仅交换数组h中的值
void heap_swap(int a, int b)
{
    swap(ph[hp[a]],ph[hp[b]]);//1、交换数组下标
    swap(hp[a], hp[b]);       //2、交换插入顺序
    swap(h[a], h[b]);         //3、交换数组的值
}
//down模板，大的下移
void down(int u)
{
    int t = u;
    //如果左儿子存在，且左儿子的值小于父亲，选择左儿子
    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;            
    //如果右儿子存在，且右儿子的值小于父亲，选择右儿子
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    //如果进行了选择，交换父亲与选中的儿子，且对选中的儿子进行下一次down
    if (u != t)                                                
    {
        heap_swap(u, t);
        down(t);
    }
}
//up模板,小的上移
void up(int u)
{
    //只要父亲存在且 父亲的值小于当前节点的值，就上移，且更新节点为父亲
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

int main()
{
    int n, m = 0;
    scanf("%d", &n);
    while (n -- )
    {
        char op[5];
        int k, x;
        scanf("%s", op);
        //1、插入一个数x，这是一个小根堆
        if (!strcmp(op, "I"))
        {
            scanf("%d", &x);
            cnt ++ ;//表示用到的第cnt个数组位置
            m ++ ;  //表示第m个插入的数
            ph[m] = cnt, hp[cnt] = m;
            h[cnt] = x;//插入数组值
            up(cnt);   //插入的时候默认有了父亲，在数组树有了一个位置，需要判断是不是需要向上走找到自己该有的位置（和数组建堆模板相反）
            //如果不想上走的话，当前的位置也可以找到当前节点的父亲   cnt/2
        }
        //2、输出小根堆的第一个，也就是最小值
        else if (!strcmp(op, "PM")) printf("%d\n", h[1]);
        //3、删除最小值，也就是用最后一个交换第一个，然后将最后一个下移，找到自己应该去往的位置
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, cnt);
            cnt -- ;
            down(1);
        }
        //4、删除第k个插入的数
        else if (!strcmp(op, "D"))
        {
            scanf("%d", &k);
            k = ph[k];        //找到第k个插入的数在数组中的位置
            heap_swap(k, cnt);//交换第k个插入的数 与最后一个
            cnt -- ;          //删除第k个插入的数
            //在不确定的情况下，up与down都执行一次，二选一执行不需要判别了
            up(k);
            down(k);
        }
        //5、修改第k个插入的数，改为x
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];//找到第k个插入的数在数组中的位置
            h[k] = x; //在数组中将第k个插入的数替换为x
            //在不确定的情况下，up与down都执行一次，二选一执行不需要判别了
            up(k);
            down(k);
        }
    }

    return 0;
}