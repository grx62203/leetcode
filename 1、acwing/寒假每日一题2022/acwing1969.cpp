/*

*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int M = 1000010;

int n, k;
int cnt[M];

int main()
{
    scanf("%d%d", &n, &k);

    int res = -1;
    queue<int> q;
    for (int i = 0; i < n; i ++ )
    {
        int id;
        scanf("%d", &id);

        if (cnt[id] > 0) res = max(res, id);
        cnt[id] ++ ;
        q.push(id);
        if (q.size() > k)
        {
            cnt[q.front()] -- ;
            q.pop();
        }
    }

    printf("%d\n", res);
    return 0;
}