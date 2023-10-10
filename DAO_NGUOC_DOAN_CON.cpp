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
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int n;

void solve()
{
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    bool ok = true;
    vector<ii> ans;
    for(int i=1, j=0; i<n; i++)
    {
        //cout << j << " " << i << "\n";
        if (a[i] < a[i - 1])
        {
            if (i == n - 1) ans.pb(mp(j + 1, i + 1));
            continue;
        }
        if (i < n && a[j] >= a[i])
        {
            ok = false;
            break;
        }
        ans.pb(mp(j + 1, i));
        j = i;
    }

    if (!ok) cout << -1;
     else
     {
         cout << sz(ans) << "\n";
         for(auto [l, r] : ans)
         {
             cout << l << " " << r << "\n";
         }
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
