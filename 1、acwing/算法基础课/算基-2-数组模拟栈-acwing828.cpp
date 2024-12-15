/*
实现一个栈，栈初始为空，支持四种操作：

push x – 向栈顶插入一个数 x；
pop – 从栈顶弹出一个数；
empty – 判断栈是否为空；
query – 查询栈顶元素。
现在要对栈进行 M 个操作，其中的每个操作 3 和操作 4 都要输出相应的结果。

输入格式
第一行包含整数 M，表示操作次数。

接下来 M 行，每行包含一个操作命令，操作命令为 push x，pop，empty，query 中的一种。

输出格式
对于每个 empty 和 query 操作都要输出一个查询结果，每个结果占一行。

其中，empty 操作的查询结果为 YES 或 NO，query 操作的查询结果为一个整数，表示栈顶元素的值。

数据范围
1≤M≤100000
1≤x≤109
所有操作保证合法。
*/
#include <iostream>

using namespace std;

const int N = 100010;

int m;
int stk[N], tt;//tt默认为 0 ，栈为空

int main()
{
    cin >> m;
    while (m -- )
    {
        string op;//读入字符用读入字符串的话更鲁棒
        int x;

        cin >> op;
        if (op == "push")//插入栈顶，可能会覆盖前面弹出的数组位置
        {
            cin >> x;
            stk[ ++ tt] = x;
        }
        else if (op == "pop") tt -- ;//弹出栈顶也就是变tt （只是不再索引，数组中还存在这个元素）
        else if (op == "empty") cout << (tt ? "NO" : "YES") << endl;//查询是否为空
        //printf(“%s”,tt ? “No” : “Yes”);
        else cout << stk[tt] << endl;//查询栈顶
    }

    return 0;
}