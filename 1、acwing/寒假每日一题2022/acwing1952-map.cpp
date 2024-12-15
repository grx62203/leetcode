/*

*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 2e9;

int n, x, y, z;

int main()
{
    map<int, int> b;

    scanf("%d%d%d%d", &n, &x, &y, &z);
    for (int i = 0; i < n; i ++ )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        b[-INF] += x;
        b[l] += y - x;
        b[r + 1] += z - y;
        b[INF] -= z;
    }

    int res = 0, sum = 0;
    for (auto& [k, v]: b)
    {
        sum += v;
        res = max(res, sum);
    }

    printf("%d\n", res);
    return 0;
}
