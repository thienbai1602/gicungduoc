#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 1e5 + 66;

int n;
ll a, b;
ii fruit[mxN];
priority_queue<ll> pq;

void solve()
{
    cin >> n >> a >> b;
    for(int i=0; i<n; i++)
    {
        cin >> fruit[i].fi >> fruit[i].se;
    }

    sort(fruit, fruit + n);

    ll ans = 0, pos = 0;
    for(ll cur_time=a; cur_time<b; cur_time++)
    {
        while(pos < n && fruit[pos].fi <= cur_time)
        {
            pq.push(fruit[pos++].se);
        }

        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        } else
        {
            cur_time = fruit[pos].fi - 1;
        }

        if (pq.empty() && pos == n) break;
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
