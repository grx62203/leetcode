/*
维护一个字符串集合，支持两种操作：

I x 向集合中插入一个字符串 x；
Q x 询问一个字符串在集合中出现了多少次。
共有 NN 个操作，输入的字符串总长度不超过 105，字符串仅包含小写英文字母。

输入格式
第一行包含整数 N，表示操作数。

接下来 N 行，每行包含一个操作指令，指令为 I x 或 Q x 中的一种。

输出格式
对于每个询问指令 Q x，都要输出一个整数作为结果，表示 x 在集合中出现的次数。

每个结果占一行。

数据范围
1≤N≤2∗104
*/
#include <iostream>

using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx;//表示每个N的26个字母子叶是否存在与指向、表示每个N作为结尾的字符串的个数、idx表示已经使用到的id
//插入字典树的时候，idx不能插入0，必须从1开始插入树里面
char str[N];//表示 一个临时字符串
//向字典树插入一个字符串
void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';//用ASCII做差表示字母
        //如果p的对应字母儿子不存在，将idx自增再插入p的儿子
        if (!son[p][u]) son[p][u] = ++ idx;//从1开始
        //将p更新为 p的儿子
        p = son[p][u];
    }
    //插入字符串之后，更新字符串最后一个字母的 结尾计数
    cnt[p] ++ ;
}
//查询字符串是否存在，返回存在的次数
int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    //因为字符串的第一个是总是树的第一层，所以N作为结尾的字符串是同一个字符串
    return cnt[p];
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        char op[2];//识别操作，也就是识别字符串
        scanf("%s%s", op, str);
        if (*op == 'I') insert(str);
        else printf("%d\n", query(str));
    }

    return 0;
}