#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 2e5 + 66;

int n, m, pi[mxN];
ll diffE[mxN], diffB[mxN], a[mxN];

void solve()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    --n;
    for(int i=0; i<n; i++)
    {
        diffE[i] = a[i] - a[i + 1];
    }

    for(int i=0; i<m; i++)
    {
        cin >> a[i];
    }

    --m;
    for(int i=0; i<m; i++)
    {
        diffB[i] = a[i] - a[i + 1];
    }

    set0(pi); pi[0] = 0;
    for(int i=1, j=0; i<m; i++)
    {
        while(j > 0 && diffB[i] != diffB[j])
        {
            j = pi[j - 1];
        }
        j += (diffB[i] == diffB[j]);
        pi[i] = j;
    }

    ll ans = 0, i = 0, j = 0;
    while(i < n)
    {
        if (j < m && diffE[i] == diffB[j])
        {
            ++i, ++j;
            if (j == m) ++ans;
        } else if (j > 0) j = pi[j - 1];
         else ++i;
    }
    cout << (m == 0 ? n+1 : ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
