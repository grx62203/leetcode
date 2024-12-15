/*

*/
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 100010, INF = 1e8;

int n;
PII q[N];
int smax[N], smin[N];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++ ) scanf("%d%d", &q[i].x, &q[i].y);

    sort(q + 1, q + n + 1);

    smax[0] = -INF, smin[n + 1] = INF;
    for (int i = 1; i <= n; i ++ ) smax[i] = max(smax[i - 1], q[i].y);
    for (int i = n; i; i -- ) smin[i] = min(smin[i + 1], q[i].y);

    int res = 0;
    for (int i = 1; i <= n; i ++ )
        if (smax[i - 1] < q[i].y && smin[i + 1] > q[i].y)
            res ++ ;

    printf("%d\n", res);
    return 0;
}