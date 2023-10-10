#include    <bits/stdc++.h>
#define ll unsigned long long
#define sz(x) (int)x.size()
#define mp make_pair
#define ii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

ll n, K, mx = 0;
vector<ll> cost;

ll ck(ll n, ll k)
{
    ll ans = 1;
    for(ll i=n-k+1, ct=1; i<=n; i++)
    {
        ans = (ll)(ans * i);
        while(ct <= k && (ans % ct) == 0)
        {
            ans = (ll)(ans / ct);
            ct++;
        }
    }
    return (ll)ans;
}

void solve()
{
    cin >> n >> K;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        mx = max(mx, x);
    }
    cout << ck(n + K - 1, min(K, n - 1)) << " " << mx * K;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
