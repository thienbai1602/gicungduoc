#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 3e6 + 66;

ll T, n, G[mxN];
deque<int> dq_dec, dq_inc;

void push(int id)
{
    while(!dq_dec.empty() && G[id] >= G[dq_dec.back()]) dq_dec.pop_back();
    dq_dec.pb(id);
    while(!dq_inc.empty() && G[id] <= G[dq_inc.back()]) dq_inc.pop_back();
    dq_inc.pb(id);
}

void pop(int id)
{
    if (!dq_dec.empty() && dq_dec.front() == id) dq_dec.pop_front();
    if (!dq_inc.empty() && dq_inc.front()== id) dq_inc.pop_front();
}

void solve()
{
    cin >> T >> n;
    for(int i=0; i<n; i++)
    {
        cin >> G[i];
    }

    ll ans = 0, j = 0;
    for(ll i=0; i<n; i++)
    {
        while(true)
        {
            if (dq_dec.empty() || (j + 1 < n && max(G[j + 1], G[dq_dec.front()]) - min(G[j + 1], G[dq_inc.front()]) <= T))
            {
                push(++j);
            } else break;
        }
        ans = max(ans, j - i + 1);
        pop(i);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("CHUNGKHOAN.INP", "r", stdin);
    //freopen("CHUNGKHOAN.OUT", "w", stdout);
    solve();
    return 0;
}


