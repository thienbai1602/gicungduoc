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

int d, s;

void solve()
{
    cin >> d >> s;
    queue<ii> que;
    vector<vector<int>> dp(s + 1, vector<int>(d, 0));
    vector<vector<ii>> listID(s + 1, vector<ii>(d, mp(0, 0)));
    que.push(mp(0, 0));
    while(!que.empty())
    {
        ii nxt = que.front();
        que.pop();

        for(int digit=0; digit<10; digit++)
        {
            int u = digit + nxt.fi;
            int v = (digit + nxt.se * 10) % d;
            if (u > s || dp[u][v] != 0) continue;
            dp[u][v] = dp[nxt.fi][nxt.se] + 1;
            que.push(mp(u, v));
            listID[u][v] = nxt;
        }
    }

    if (dp[s][0] == 0) cout << -1;
     else
     {
         vector<int> ans;
         ii ret = mp(s, 0);
         while(ret.fi != 0)
         {
             ans.pb(ret.fi - listID[ret.fi][ret.se].fi);
             ret = listID[ret.fi][ret.se];
         }

         reverse(all(ans));
         for(int &x : ans) cout << x;
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

