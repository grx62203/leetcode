/*
试除法判定质数
给定 n 个正整数 ai，判定每个数是否是质数。
输入格式
第一行包含整数 n。
接下来 n 行，每行包含一个正整数 ai。
输出格式
共 n 行，其中第 i 行输出第 i 个正整数 ai 是否为质数，是则输出 Yes，否则输出 No。
*/
#include <iostream>
#include <algorithm>

using namespace std;

//返回是不是质数，质数只有1和本身两个约数
bool is_prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )//遍历到根号n就可以了，因为约数是成双出现的
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        int x;
        cin >> x;
        if (is_prime(x)) puts("Yes");
        else puts("No");
    }

    return 0;
}
