#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = (1LL << 32);

int Q;
bitset<MOD + 1> bit;
ll A, B, S;

void solve()
{
    cin >> Q >> S >> A >> B;
    while(Q--)
    {
        if (S & 1)
        {
            bit[S / 2] = 1;
        } else
        {
            bit[S / 2] = 0;
        }
        S = (S * A + B) % MOD;
    }

    ll ret = 0;
    int sz = bit.count();
    while(sz--)
    {
        ll tp = __builtin_clz(bit);
        ret += tp;
        bit[tp] = 0;
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
