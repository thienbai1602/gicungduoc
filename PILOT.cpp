#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mxN = 1e4 + 66;

int n;
ii pilot[mxN];
priority_queue<ll> pq;

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> pilot[i].fi >> pilot[i].se;
    }

    ll S = 0, ans = 0;
    for(int i=0; i<n; i++)
    {
        S += pilot[i].fi;
        pq.push(pilot[i].fi - pilot[i].se);
        if (i % 2 == 0)
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << S - ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
