#include    <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const int MOD = 100;

ll N, K, q[105], cnt[105];

ll pw(ll a, ll b)
{
    if (b == 0) return 1;
    if (b == 1) return a % MOD;
    ll t = pw(a, b / 2);
    t = ((t % MOD) * (t % MOD)) % MOD;
    return (b % 2 == 0 ? t % MOD : ((t % MOD) * (a % MOD)) % MOD);
}

void solve()
{
    cin >> K >> N;
    memset(q, 0, sizeof(q));
    for(int r=0; r<100; r++)
    {
        q[r] = N / 100 + (N % 100 >= r);
    }

    ll ret = 0;
    for(int r=0; r<100; r++)
    {
        //if (q[r] > 0) cout << r << " " << q[r] << "\n";
        //ll pk = pw(r, K + 1) % MOD;
        ret = (ret + pw(r, K + 1) * q[r]) % MOD;
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
