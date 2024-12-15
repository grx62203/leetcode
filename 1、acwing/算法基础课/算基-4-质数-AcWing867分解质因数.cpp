/*
分解质因数，  时间复杂度最坏根号n，肯定比试除法要快，最好啷个n
给定 n 个正整数 ai，将每个数分解质因数，并按照质因数从小到大的顺序输出每个质因数的底数和指数。
输入格式
第一行包含整数 n。
接下来 n 行，每行包含一个正整数 ai。
输出格式
对于每个正整数 ai，按照从小到大的顺序输出其分解质因数后，每个质因数的底数和指数，每个底数和指数占一行。
每个正整数的质因数全部输出完毕后，输出一个空行。
*/
#include <iostream>
#include <algorithm>

using namespace std;

//分解质因数模板
void divide(int x)
{
    for (int i = 2; i <= x / i; i ++ )//n中只有一个大于 根号n 的质因子
        if (x % i == 0)               //如果 i一定是质数
        {
            int s = 0;
            while (x % i == 0) x /= i, s ++ ;//i是底数、s是i对应的指数
            cout << i << ' ' << s << endl;
        }
    if (x > 1) cout << x << ' ' << 1 << endl;//x会除以i 变小，最后剩下的数如果大于1 且 无法被整除了，也是x的质因数
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        int x;
        cin >> x;
        divide(x);
    }

    return 0;
}