#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6 + 66;

int n, pos[mxN];

void solve()
{
    cin >> n;
    memset(pos, 0, sizeof(pos));
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        pos[x] = i;
    }

    int nxt = 1;
    for(int i=1, cur=1; i<=n; i++)
    {
        if (i == n)
        {
            nxt = max(nxt, cur);
        } else
        {
            if (pos[i] < pos[i + 1])
            {
                cur++;
            } else
            {
                nxt = max(nxt, cur);
                cur = 1;
            }
        }
    }
    cout << n - nxt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
