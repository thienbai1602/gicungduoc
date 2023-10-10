#include    <bits/stdc++.h>
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

ll N, X;

void solve()
{
    cin >> N >> X;
    ll Y = 1, fac = 2;
    while(fac * fac <= X)
    {
        int cnt = 0;
        while(X % fac == 0)
        {
            X /= fac;
            ++cnt;
        }
        if (cnt & 1) Y *= fac;
        ++fac;
    }

    if (X > 1) Y *= X;d
    cout << (ll)sqrt(N / Y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
