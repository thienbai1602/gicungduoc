#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

ll A, B;

void solve()
{
    cin >> A >> B;
    if (A > B) swap(A, B);
    ll ret = 1;
    for(ll x=1; x<=A; x++)
    {
        ret = (ret * x) % MOD;
    }
    cout << ret % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("MAXGCD.INP", "r", stdin);
    freopen("MAXGCD.OUT", "w", stdout);
    solve();
    return 0;
}
