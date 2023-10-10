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
const int mxN = 1e6 + 66;

int n, m;

int bs(vector<ll>& u, vector<int>& b, int l, int r, ll X)
{
    int ret = 0;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if (u[b[m]] < X)
        {
            ret = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    return ret;
}

bool operator < (vector<ll>& a, vector<ll>& b)
{
    for(int i=0; i<m; i++)
    {
        if (a[i] >= b[i]) return false;
    }
    return true;
}

void solve()
{
    cin >> n >> m;
    if (m == 1)
    {
        vector<ll> u(n);
        for(int i=0; i<n; i++)
        {
            cin >> u[i];
        }

        vector<int> b(n + 1, 0), ans(n, 0);
        ans[0] = 1, b[1] = 0;
        int l = 0;
        for(int i=1; i<n; i++)
        {
            int pos = bs(u, b, 1, ans[l], u[i]);
            b[pos + 1] = i;
            ans[i] = pos + 1;
            if (ans[l] < ans[i])
            {
                l = i;
            }
        }
        cout << ans[l];
    } else
    {
        vector<ll> u[n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ll x;
                cin >> x;
                u[i].pb(x);
            }
            sort(all(u[i]));
        }

        vector<int> ans(n, 1);
        int mx = 0;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if (u[j] < u[i])
                {
                    ans[i] = max(ans[i], ans[j] + 1);
                    mx = max(mx, ans[i]);
                }
            }
        }
        cout << mx;
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
