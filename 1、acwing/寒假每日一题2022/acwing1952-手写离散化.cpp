/*

*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 20010, INF = 2e9;

int n, x, y, z;
vector<int> xs;
int l[N], r[N], b[N * 2];

int find(int v)
{
    int l = 0, r = xs.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (xs[mid] >= v) r = mid;
        else l = mid + 1;
    }
    return r;
}

int main()
{
    scanf("%d%d%d%d", &n, &x, &y, &z);

    xs.push_back(-INF), xs.push_back(INF);
    for (int i = 0; i < n; i ++ )
    {
        scanf("%d%d", &l[i], &r[i]);
        xs.push_back(l[i]);
        xs.push_back(r[i] + 1);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    for (int i = 0; i < n; i ++ )
    {
        int L = find(l[i]), R = find(r[i] + 1);
        b[0] += x;
        b[L] += y - x;
        b[R] += z - y;
        b[xs.size() - 1] -= z;
    }

    int res = 0, sum = 0;
    for (int i = 0; i < xs.size(); i ++ )
    {
        sum += b[i];
        res = max(res, sum);
    }

    printf("%d\n", res);
    return 0;
}