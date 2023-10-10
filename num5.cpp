#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

ll tc, N;
vector<ll> ans;

ll pw(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if (b & 1) res = (res * a);
        a = a * a;
        b >>= 1;
    }
    return res;
}

void init()
{
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<19; j++)
        {
            for(int k=0; k<13; k++)
            {
                ll x = pw(2, i) * pw(3, j);
                if (1e10 / pw(5, k) >= x)
                {
                    x *= pw(5, k);
                    ans.pb(x);
                }
            }
        }
    }

    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
}

void solve()
{
    cin >> N;
    int pos = (upper_bound(ans.begin(), ans.end(), N) - ans.begin()) - 1;
    if (ans[pos] == N)
    {
        cout << "YES " << pos + 1 << "\n";
    } else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("NUM5.INP", "r", stdin);
    freopen("NUM5.OUT", "w", stdout);
    init();
    cin >> tc;
    while(tc--) solve();
    return 0;
}
