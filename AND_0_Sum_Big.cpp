#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

int tc;
ll N, K;

void solve()
{
    cin >> N >> K;
    ll ret = 1;
    for(int i=0; i<K; i++)
    {
        ret = (ret * N ) % MOD;
    }
    cout << ret << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
