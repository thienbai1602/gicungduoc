#include    <bits/stdc++.h>
#define ll long long
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

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int n;
ll K, a[mxN];
deque<ll> dq_inc, dq_dec;

void push(int id)
{
    while(!dq_dec.empty() && a[dq_dec.back()] <= a[id]) dq_dec.pop_back();
    dq_dec.pb(id);
    while(!dq_inc.empty() && a[dq_inc.back()] >= a[id]) dq_inc.pop_back();
    dq_inc.pb(id);
}

void pop(int id)
{
    if (!dq_dec.empty() && dq_dec.front() == id) dq_dec.pop_front();
    if (!dq_inc.empty() && dq_inc.front() == id) dq_inc.pop_front();
}

void solve()
{
    cin >> n >> K;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    for(int i=1, j=0; i<=n; i++)
    {
        while(dq_dec.empty() || (j < n && max(a[j + 1], a[dq_dec.front()]) - min(a[j + 1], a[dq_inc.front()]) <= K))
        {
            push(++j);
        }
        ans += (j - i + 1);
        pop(i);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("demcap.inp", "r", stdin);
    freopen("demcap.out", "w", stdout);
    solve();
    return 0;
}
