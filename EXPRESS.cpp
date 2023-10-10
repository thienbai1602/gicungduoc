#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 1e5 + 66;

int n, K;
ll a[mxN];
vector<ll> val;

void solve()
{
    cin >> n >> K;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        if (i != 0) val.pb(a[i]);
    }

    sort(all(val), greater<ll>());

    ll ans = a[0];
    for(int i=0; i<K; i++)
    {
        ans += val[i];
    }

    for(int i=K; i<n-1; i++)
    {
        ans -= val[i];
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
