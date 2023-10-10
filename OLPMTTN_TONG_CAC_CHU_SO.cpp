#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

ll N, K;
vector<int> num;
ll dp[14][(ll)1e5 + 5][2], ways[14][(ll)1e5 + 5][2];

int sum_dig(ll X)
{
    int ret = 0;
    while(X > 0)
    {
        ret += X % 10;
        X /= 10;
    }
    return ret;
}

ii recur(int siz, int module, bool tight)
{
    if (siz == 0)
    {
        if (module == 0) return mp(0, 1);
         else return mp(0, 0);
    }

    if (ways[siz][module][tight] != -1 && dp[siz][module][tight]) return mp(dp[siz][module][tight], ways[siz][module][tight]);

    ii ans = mp(0, 0);
    int limit = tight ? num[sz(num) - siz] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        ii nxt = recur(siz - 1, (module * 10 + digit) % K, tight && (digit == limit));
        ans = mp(ans.fi + nxt.fi + digit * nxt.se, ans.se + nxt.se);
    }
    return mp(dp[siz][module][tight] = ans.fi, ways[siz][module][tight] = ans.se);
}

ll sol(ll X)
{
    num.clear();
    while(X > 0)
    {
        num.pb(X % 10);
        X /= 10;
    }
    reverse(all(num));
    memset(dp, -1, sizeof(dp));
    memset(ways, -1, sizeof(ways));
    return recur(sz(num), 0, 1).fi;
}

void solve()
{
    //if (N == 0) exit(0);
    if(K >= (ll)1e5)
    {
        ll ans = 0;
        for(ll i=K; i<=N; i+=K)
        {
            ans += sum_dig(i);
        }
        cout << ans << "\n";
    } else
    {
        cout << sol(N) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(cin >> N >> K) solve();
    return 0;
}
