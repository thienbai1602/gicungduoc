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

string N;

ll digit(char c)
{
    return (int)(c - '0');
}

void solve()
{
    cin >> N;
    ll ans = 0, cur = 0, sq = 0;
    for(int i=0; i<sz(N); i++)
    {
        (sq *= 100) %= MOD;
        (cur *= 10) %= MOD;
        (sq += (cur * digit(N[i]) * 2 + (i + 1) * digit(N[i]) * digit(N[i]))) %= MOD;
        (cur += (i + 1) * digit(N[i])) %= MOD;
        (ans += sq) %= MOD;
        //cout << cur << " " << sq << " " << ans << "\n";
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
