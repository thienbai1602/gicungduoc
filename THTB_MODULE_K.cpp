#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, M, K;

void solve()
{
    cin >> N >> K >> M;
    ll nxt = N / K;
    // so du
    ll q = M / nxt;
    // con lai
    ll p = M - q * nxt;
    //cout << nxt << " " << q << " " << p << "\n";

    if (p == 0)
    {
        cout << (q - 1) + (nxt - 1) * K;
    } else
    {
        cout << q + (p - (q != 0)) * K;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("MODK.inp", "r", stdin);
    freopen("MODK.out", "w", stdout);
    solve();
    return 0;
}
