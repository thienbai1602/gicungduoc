#include    <bits/stdc++.h>
#define ll long long
#define ld long double
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

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int n, X[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        ++X[a], X[b + 1]--;
    }

    int mx = 0;
    for(int i=1; i<=(int)1e6; i++)
    {
        X[i] += X[i - 1];
        mx = max(mx, X[i]);
    }

    int cnt = 0;
    for(int i=1; i<=(int)1e6; i++)
    {
        if (X[i] == mx) ++cnt;
    }
    cout << mx << "\n" << cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
