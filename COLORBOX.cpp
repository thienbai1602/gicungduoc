#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6 + 66;
const int INF = 1e7 + 66;

int n;
int a[mxN], cnt[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int nxt = 0;
    for(int i=0; i<n; i++)
    {
        nxt += (++cnt[a[i]] == 2);
    }

    int ret = INF;
    for(int l=0, r=-1; l<n; l++)
    {
        while(r < n)
        {
            if (nxt == 0)
            {
                ret = min(ret, r - l + 1);
                break;
            }

            ++r;
            if (r < n) nxt -= (--cnt[a[r]] == 1);
        }
        nxt += (++cnt[a[l]] == 2);
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
