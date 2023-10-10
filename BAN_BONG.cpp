#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

const int mxN = 1e5 + 66;

int n;
ll m, K;
ii ball[mxN];

void solve()
{
    cin >> n >> m >> K;
    for(int i=0; i<n; i++)
    {
        cin >> ball[i].fi >> ball[i].se;
    }

    sort(ball, ball + n);

    multiset<ll> store;
    for(int i=0; i<n; i++)
    {
        if (ball[i].se <= m)
        {
            store.insert(ball[i].fi);
        } else
        {
            store.insert(ball[i].fi + ball[i].se - m);
        }
    }

    ll ans = 0;
    while(!store.empty() && K > 0)
    {
        if (*store.begin() > K) break;
        ++ans;
        K -= *store.begin();
        store.erase(store.begin());
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
