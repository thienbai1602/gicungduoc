#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;

bool sf(ll X)
{
    ll ans = 0;
    for(; X>0; X/=10)
    {
        ll nxt = X % 10;
        ans += nxt * nxt;
    }

    if (ans == 1) return false;
    for(ll i=2; i*i<=ans; i++)
    {
        if (ans % i == 0) return false;
    }
    return true;
}

void solve()
{
    cin >> N;
    while(1)
    {
        ++N;
        if (sf(N)) break;
    }
    cout << N;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
