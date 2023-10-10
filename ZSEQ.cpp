#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
map<ll, ll> ma;
ll ret = 0, S = 0;

void solve()
{
    cin >> N;
    ma[0] = 1;
    for(int i=0; i<N; i++)
    {
        ll x;
        cin >> x;
        S += x;
        if (ma[S]) ret += ma[S];
        ++ma[S];
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("ZSEQ.INP", "r", stdin);
    freopen("ZSEQ.OUT", "w", stdout);
    solve();
    return 0;
}
