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

const int mxN = 5e6 + 66;

deque<int> dq_dec, dq_inc;
ll n, p, q, m, T, w[mxN];

void push(int id)
{
    while(!dq_dec.empty() && w[id] >= w[dq_dec.back()]) dq_dec.pop_back();
    dq_dec.pb(id);
    while(!dq_inc.empty() && w[id] <= w[dq_inc.back()]) dq_inc.pop_back();
    dq_inc.pb(id);
}

void pop(int id)
{
    if (!dq_dec.empty() && dq_dec.front() == id) dq_dec.pop_front();
    if (!dq_inc.empty() && dq_inc.front() == id) dq_inc.pop_front();
}

void solve()
{
    cin >> n >> p >> q >> m >> T;
    for(ll i=1; i<=n; i++)
    {
        w[i] = (p * i + q) % m;
    }

    ll j = 0, ans = 0;
    for(ll i=1; i<=n; i++)
    {
        while(true)
        {
            if (dq_dec.empty() || (j + 1 <= n && max(w[j + 1], w[dq_dec.front()]) - min(w[j + 1], w[dq_inc.front()]) <= T))
            {
                push(++j);
                ans += (j - i + 1);
            } else break;
        }
        pop(i);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}


