#include    <bits/stdc++.h>
//#define SKY
#define ll long long
#define ld long double
#define MASK(x) (1LL << x)
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

ll M, pref[mxN];
int N, cnt[mxN];

void solve()
{
    cin >> N >> M;
    set0(cnt);
    for(int i=0; i<N; i++)
    {
        ll x;
        cin >> x;
        if (x > (int)1e6) continue;
        ++cnt[x];
    }

    ll S = 0;
    vector<ll> ans;
    for(ll x=1; x<=(ll)1e6; x++)
    {
        if (!cnt[x])
        {
            if (S + x <= M)
            {
                S += x;
                ans.pb(x);
            } else break;
        }
    }

    cout << sz(ans) << "\n";
    for(ll &x : ans) cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif //SKY
    solve();
    return 0;
}
