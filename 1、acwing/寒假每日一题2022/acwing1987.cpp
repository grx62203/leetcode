/*

*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    map<int, int> b;
    int n;
    scanf("%d", &n);

    int x = 0, y;
    char s[2];
    while (n -- )
    {
        scanf("%d%s", &y, s);
        if (*s == 'R')
        {
            b[x] ++ ;
            b[x + y] -- ;
            x += y;
        }
        else
        {
            b[x - y] ++ ;
            b[x] -- ;
            x -= y;
        }
    }

    int res = 0, sum = 0, last;
    for (auto& [x, v]: b)
    {
        if (sum >= 2) res += x - last;
        sum += v;
        last = x;
    }

    printf("%d\n", res);

    return 0;
}