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

bool dx(ll X)
{
    if (X > N) return false;
    ll tp = X;
    vector<int> num, rev;
    while(X > 0)
    {
        num.pb(X % 10);
        rev.pb(X % 10);
        X /= 10;
    }

    if (sz(num) > 2)
    {
        int cur = num[0];
        for(int i=1; i<(sz(num) + 1)/2; i++)
        {
            if (cur >= num[i]) return false;
            cur = num[i];
        }
    }

    reverse(all(rev));
    for(int i=0; i<sz(num); i++)
    {
        if (rev[i] != num[i]) return false;
    }
    return true;
}

int sf(ll x)
{
    ll rev = 0, fin = x, pw = 1;
    while(x)
    {
        rev = rev * 10 + (x % 10);
        x /= 10;
        pw *= 10;
    }
    return dx(fin * pw + rev) + (fin > 9 ? dx(fin * (pw / 10) + (rev % (pw / 10))) : 0);
}


void solve()
{
    cin >> N;
    if (N < 10)
    {
        cout << N;
        return;
    }

    ll ans = 9;
    for(ll x=1; x<=(ll)1e5; x++)
    {
        ans += sf(x);
        //if (sf(x) > 0) cout << sf(x) << " " << x << "\n";
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
