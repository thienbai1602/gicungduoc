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
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 2e5 + 66;

ll M;
int n, tc;

void solve()
{
    cin >> n >> M;
    vector<ll> nxt(n);
    for(int i=0; i<n; i++)
    {
        cin >> nxt[i];
    }

    ll curB = 0;
    vector<ll> a, b;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            a.pb(nxt[i]);
        } else
        {
            b.pb(nxt[i]);
            curB += nxt[i];
        }
    }

    sort(rall(a));
    sort(rall(b));

    ll ans = inf, curA = 0, r = sz(b);
    for(int l=0; l<=sz(a); l++)
    {
        while(r > 0 && curA + curB - b[r - 1] >= M)
        {
            curB -= b[--r];
        }

        if (curA + curB >= M)
        {
            ans = min(ans, l + r * 2);
        }

        if (l != sz(a))
        {
            curA += a[l];
        }
    }
    cout << (ans == inf ? -1 : ans) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> tc;
    while(tc--) solve();
    return 0;
}

