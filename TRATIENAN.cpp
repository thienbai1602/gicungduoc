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
const int mxN = 2e6 + 66;

int n, K;
ll a[mxN], dif[mxN];
deque<int> dq;
multiset<ll> store;

void push(int id)
{
    while(!dq.empty() && dif[id] <= dif[dq.back()]) dq.pop_back();
    dq.pb(id);
}

void pop(int id)
{
    if (!dq.empty() && id == dq.front()) dq.pop_front();
}

void solve()
{
    cin >> n >> K;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    for(int i=0; i<n; i++)
    {
        a[i + n] = a[i];
    }

    for(int i=1; i<2*n; i++)
    {
        dif[i] = abs(a[i] - a[i - 1]);
    }

    store.insert(a[0]);
    for(int i=1; i<n-K-1; i++)
    {
        push(i);
        store.insert(a[i]);
    }

    ll ans = INF;
    for(int i=n-K-1; i<2*n; i++)
    {
        push(i);
        store.insert(a[i]);
        ans = min(ans, *store.rbegin() - * store.begin() + dif[dq.front()]);
        store.erase(store.find(a[i-n+K+1]));
        pop(i-n+K+1);
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


