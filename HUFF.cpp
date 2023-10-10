#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int n;
ll a[mxN];
priority_queue<ll, vector<ll>, greater<ll>> pq;

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        pq.push(a[i]);
    }

    ll ans = 0;
    for(int i=1; i<n; i++)
    {
        ll x = pq.top(); pq.pop();
        ll y = pq.top(); pq.pop();
        ans += x + y;
        pq.push(x + y);
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
