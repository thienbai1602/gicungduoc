#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;

bool check(ll a, ll b)
{
    ll u = (a + b - 1);
    ll v = b - u / 2;
    if (u % 2 != 0) return false;
    return (u/2 > 0 && v > 0 && u/2 <= N && v <= N);
}

void solve()
{
    cin >> N; N *= 2;
    ll ret = 0;
    for(ll div=1; div<=(ll)sqrt(N); div++)
    {
        if (N % div == 0)
        {
            ret += check(div, N / div);
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);
    solve();
    return 0;
}
