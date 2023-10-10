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
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

ll cnt[mxN];
int A, B, C, D;

void solve()
{
    cin >> A >> B >> C >> D;
    for(int x=A; x<=B; x++)
    {
        ++cnt[x + B];
        --cnt[x + C + 1];
    }

    for(int i=1; i<=(int)1e6+6; i++)
    {
        cnt[i] += cnt[i - 1];
    }

    for(int i=1; i<=(int)1e6+6; i++)
    {
        cnt[i] += cnt[i - 1];
    }

    ll ans = 0;
    for(int z=C; z<=D; z++)
    {
        ans += cnt[(int)1e6+6] - cnt[z];
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
