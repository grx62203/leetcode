/*
实现一个队列，队列初始为空，支持四种操作：

push x – 向队尾插入一个数 x；
pop – 从队头弹出一个数；
empty – 判断队列是否为空；
query – 查询队头元素。
现在要对队列进行 M 个操作，其中的每个操作 3 和操作 4 都要输出相应的结果。

输入格式
第一行包含整数 M，表示操作次数。

接下来 M 行，每行包含一个操作命令，操作命令为 push x，pop，empty，query 中的一种。

输出格式
对于每个 empty 和 query 操作都要输出一个查询结果，每个结果占一行。

其中，empty 操作的查询结果为 YES 或 NO，query 操作的查询结果为一个整数，表示队头元素的值。

数据范围
1≤M≤100000
1≤x≤109
所有操作保证合法。
*/
#include <iostream>

using namespace std;

const int N = 100010;

int m;
int q[N], hh, tt = -1;//队头默认0，队尾默认 -1为空，有一个的时候为 0

int main()
{
    cin >> m;

    while (m -- )
    {
        string op;
        int x;

        cin >> op;
        if (op == "push")
        {
            cin >> x;
            q[ ++ tt] = x;//雷同数组模拟栈，有可能覆盖弹出的元素所在的数组位置
        }
        else if (op == "pop") hh ++ ;//弹出也是取消链接，不删除数组中的此个元素
        else if (op == "empty") cout << (hh <= tt ? "NO" : "YES") << endl;
        else cout << q[hh] << endl;
    }

    return 0;
}