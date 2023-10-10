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

int n, K;
string S;

void solve()
{
    cin >> n >> K >> S;
    vector<int> nxt(n + 1, -1);
    for(int i=n-1; i>=0; i--)
    {
        nxt[i] = (S[i] == 'L' ? i : nxt[i + 1]);
    }

    vector<int> L, Q, D;
    for(int i=0; i<sz(S); i++)
    {
        if (S[i] == 'L') L.pb(i);
        if (S[i] == 'Q') Q.pb(i);
        if (S[i] == 'D') D.pb(i);
    }

    ll ans = INF;
    for(int i=0; i+K-1<sz(L); i++)
    {
        int cur = L[i + K - 1];
        if (cur > Q.back()) break;
        int iter = lower_bound(all(Q), cur) - Q.begin();
        if (iter + K - 1 < sz(Q)) iter = Q[iter + K - 1];
         else break;
        if (iter > D.back()) break;
        iter = lower_bound(all(D), iter) - D.begin();
        if (iter + K - 1 < sz(D)) iter = D[iter + K - 1];
         else break;
        ans = min(ans, (ll)(iter - L[i] + 1) - 3 * K);
    }
    cout << (ans == INF ? -1 : ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
