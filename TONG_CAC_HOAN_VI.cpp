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

ll N;
vector<int> num;

void solve()
{
    cin >> N;
    while(N > 0)
    {
        num.pb(N % 10);
        N /= 10;
    }

    ll ans = 0;
    sort(all(num));
    do
    {
        if (num[0] == 0) continue;
        ll X = 0;
        for(int i=0; i<sz(num); i++)
        {
            X = X * 10 + num[i];
        }
        ans += X;
        cout << X << "\n";
    }while(next_permutation(all(num)));
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
