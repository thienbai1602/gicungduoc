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

int N, X;
ll p[mxN], pref[mxN];
ll mi = INF, mx = -INF;

ll sol(ll dv)
{
    ll nxt = X / dv;
    if (nxt < mi * dv * 2 || nxt > mx * dv * 2)
    {
        return 0;
    }

    vector<ll> cnt(nxt + 1, 0);
    for(int i=1; i<=N-dv+1; i++)
    {
        ll val = pref[i + dv - 1] - pref[i - 1];
        if (val <= nxt)
        {
            ++cnt[val];
        }
    }

    ll ret = 0;
    for(int i=1; i<=N-dv+1; i++)
    {
        ll val = nxt - (pref[i + dv - 1] - pref[i - 1]);
        if (val > 0 && val <= nxt)
        {
            ret += cnt[val];
        }
    }
    return ret;
}

void solve()
{
    cin >> N >> X;
    for(int i=1; i<=N; i++)
    {
        cin >> p[i];
        mx = max(mx, p[i]);
        mi = min(mi, p[i]);
    }

    set0(pref);
    for(int i=1; i<=N; i++)
    {
        pref[i] = pref[i - 1] + p[i];
    }

    vector<ll> divisor;
    for(int x=1; x*x<=X; x++)
    {
        if (X % x == 0)
        {
            divisor.pb(x);
            if (X / x != x && X / x <= N)
            {
                divisor.pb(X / x);
            }
        }
    }

    ll ans = 0;
    for(ll k : divisor)
    {
        ans += sol(k);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
