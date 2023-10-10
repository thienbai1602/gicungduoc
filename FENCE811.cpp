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
const int mxN = 1e6 + 66;

deque<int> dq;
ll n, X, h[mxN], a[mxN], b[mxN];

void push_h(int id)
{
    while(!dq.empty() && h[id] <= h[dq.back()]) dq.pop_back();
    dq.pb(id);
}

void push_a(int id)
{
    while(!dq.empty() && a[id] >= a[dq.back()]) dq.pop_back();
    dq.pb(id);
}

void pop(int id)
{
    if (!dq.empty() && id == dq.front()) dq.pop_front();
}

void solve()
{
    cin >> n >> X;
    for(int i=0; i<n; i++)
    {
        cin >> h[i];
    }

    for(int i=0; i<n; i++)
    {
        push_h(i);
        a[i] = (X - 1 > i ? 0 : h[dq.front()]);
        pop(i-X+1);
    }

    dq.clear();
    for(int i=n-1; i>=0; i--)
    {
        push_a(i);
        b[i] = a[dq.front()];
        pop(i+X-1);
    }

    ll ans = 0, ct = 1, j = 0;
    for(int i=0; i<n; i++)
    {
        if (j + X <= i || (b[i] != b[j]))
        {
            ++ct;
            j = i;
        }
        ans += (h[i] - b[i]);
    }
    cout << ans << "\n" << ct;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}


