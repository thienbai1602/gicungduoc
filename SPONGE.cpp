#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
priority_queue<ll, vector<ll>, greater<ll>> pq;

void solve()
{
    cin >> n;
    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        if (!pq.empty())
        {
            ll nxt = pq.top();
            ans += nxt;
            nxt *= 2;
            pq.pop();
            pq.push(nxt);
        }
        pq.push(x);
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
