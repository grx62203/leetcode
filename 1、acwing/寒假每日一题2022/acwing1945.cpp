/*

*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int p[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &p[i]);
    sort(p, p + n);

    int res = 0;
    for (int i = 0; i + 2 < n; i ++ )
        for (int j = i + 1, l = j + 1, r = j + 1; j + 1 < n; j ++ )
        {
            while (l < n && p[l] - p[j] < p[j] - p[i]) l ++ ;
            while (r < n && p[r] - p[j] <= 2 * (p[j] - p[i])) r ++ ;
            res += r - l;
        }

    printf("%d\n", res);
    return 0;
}

