/*

*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1 << 16;

int n;
LL m;
int p[N];

int update(int state)
{
    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int j = (i - 1 + n) % n;
        int x = state >> i & 1, y = state >> j & 1;
        res |= (x ^ y) << i;
    }
    return res;
}

void print(int state)
{
    for (int i = 0; i < n; i ++ )
        cout << (state >> i & 1) << endl;
}

int main()
{
    cin >> n >> m;

    int state = 0;
    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        state |= x << i;
    }

    memset(p, -1, sizeof p);
    p[state] = 0;

    for (int i = 1;; i ++ )
    {
        state = update(state);
        if (i == m)
        {
            print(state);
            break;
        }
        else if (p[state] == -1) p[state] = i;
        else
        {
            int len = i - p[state];
            int r = (m - i) % len;
            while (r -- ) state = update(state);
            print(state);
            break;
        }
    }

    return 0;
}