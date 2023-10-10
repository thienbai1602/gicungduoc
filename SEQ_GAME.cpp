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
const int mxN = 1e5 + 66;

int n, m, Q;

void solve()
{
    cin >> n >> m >> Q;
    vector<ll> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    vector<ll> b(m);
    for(int i=0; i<m; i++)
    {
        cin >> b[i];
    }

    sort(all(a)), sort(all(b));

    while(Q--)
    {
        int i = 0, j = m-1;
        ll s, ans = INF;
        cin >> s;
        while(i < n && j >= 0)
        {
            ans = min(ans, abs(s - (a[i] + b[j])));
            if (a[i] + b[j] <= s) ++i;
             else --j;
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
