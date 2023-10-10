#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, K, ret;

void solve()
{
    cin >> N >> K;
    ll a = K / 2, b = K - a;
    while(a == b)
    {
        a--, b++;
    }
    ret = min(a , N - b + 1);
    cout << max(ret, 1LL * 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
