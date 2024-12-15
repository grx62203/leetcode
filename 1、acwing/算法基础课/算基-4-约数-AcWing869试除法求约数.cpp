/*
试除法求约数  时间复杂度  根号n*

给定 n 个正整数 ai，对于每个整数 ai，请你按照从小到大的顺序输出它的所有约数。
输入格式
第一行包含整数 n。
接下来 n 行，每行包含一个整数 ai。
输出格式
输出共 n 行，其中第 i 行输出第 i 个整数 ai 的所有约数。
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//求n的所有约数
vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i ++ )//约数成对出现，枚举小的约数
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);//如果成对约数不相等，都添加
        }
    sort(res.begin(), res.end());//约数个数大概是 lgn 个  时间复杂度为 lgn*lgn
    return res;
}

int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        int x;
        cin >> x;
        auto res = get_divisors(x);

        for (auto x : res) cout << x << ' ';
        cout << endl;
    }

    return 0;
}