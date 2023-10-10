#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
unordered_map<ll, ll> ma;

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        ++ma[x];
    }

    ll cur = 0;
    while(1)
    {
        ll nxt = (ll)(1LL << cur);
        if (ma[nxt] == 0)
        {
            cout << nxt;
            break;
        }
        ++cur;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
