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

bool prime(ll X)
{
    for(ll k=2; k*k<=X; k++)
    {
        if (X % k == 0) return false;
    }
    return true;
}

bool ck(ll X)
{
    if (!prime(X) || X > N || X <= 10) return false;
    vector<int> num, rev;
    while(X)
    {
        num.pb(X % 10);
        rev.pb(X % 10);
        X /= 10;
    }
    reverse(all(rev));

    for(int i=0; i<sz(num); i++)
    {
        if (num[i] != rev[i]) return false;
    }
    return true;
}

int sol(ll x)
{
    ll fin = x, pw = 1, rev = 0;
    while(x > 0)
    {
        rev = rev * 10 + (x % 10);
        x /= 10;
        pw *= 10;
    }
    return ck(fin * pw + rev) + ck(fin * (pw / 10) + (rev % (pw / 10)));
}

void solve()
{
    cin >> N;
    int ans = 0;
    for(int x=1; x<=(int)1e5; x++)
    {
        ans += sol(x);
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
