#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;

void solve()
{
    cin >> N;
    ll ans = 0, cur = N * N, tp = 2;
    for(; cur>=N; cur-=tp, tp+=2)
    {
        ans += cur;
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
