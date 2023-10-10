#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

const int mxN = 1e6 + 66;

ll N, x, y;
vector<ii> walk;
ll pref[2 * mxN], g[2 * mxN], ret = 0;

void solve()
{
    cin >> N >> x >> y;
    ll cnt = 0;
    for(int i=1; i<2*N; i++)
    {
        pref[i] = pref[i - 1] + (i <= N ? ++cnt : --cnt);
    }

    string S;
    cin >> S;
    walk.pb(mp(x, y));
    for(int i=0; i<sz(S); i++)
    {
        if (S[i] == 'S') x++;
        if (S[i] == 'N') x--;
        if (S[i] == 'E') y++;
        if (S[i] == 'W') y--;
        walk.pb(mp(x, y));
    }

    sort(walk.begin(), walk.end());
    for(int id=0; id<sz(walk); id++)
    {
        if (id > 0 && walk[id] == walk[id - 1]) continue;
        ll i = walk[id].fi, j = walk[id].se;
        ll dij = i + j - 1, i2;
        if (dij % 2 == 0)
        {
            i2 = max(1LL, dij - N + 1);
        } else
        {
            i2 = min(N, dij);
        }
        ret += pref[dij - 1] + 1 + abs(i2 - i);
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
