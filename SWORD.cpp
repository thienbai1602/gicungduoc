#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;

const int mxN = 2e5 + 66;

int n;
ll S;
ii a[mxN];

void solve()
{
    cin >> n >> S;
    for(int i=0; i<n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }

    sort(a, a + n);

    int idx = -1;
    for(int i=0; i<n; i++)
    {
        if (a[i].fi >= S)
        {
            idx = i;
            break;
        } else
        {
            S += a[i].se;
        }
    }
    cout << (idx == -1 ? n : idx);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
