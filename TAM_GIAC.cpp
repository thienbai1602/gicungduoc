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

int n;
ll x, y, S;

ld sq(ld x)
{
    return (ld)x * x;
}

ld dis(ii a, ii b)
{
    return (ld)sqrt((ld)sq(a.fi - b.fi) + (ld)sq(a.se - b.se));
}

bool ck(ll u, ll v)
{
    ld a = dis(mp(u, 0), mp(v, 0));
    ld b = dis(mp(u, 0), mp(x, y));
    ld c = dis(mp(v, 0), mp(x, y));
    ld p = (a + b + c) / (ld)2;
    return (ld)sqrt(p * (p - a) * (p - b) * (p - c)) > (ld)S;
}

void solve()
{
    cin >> n >> S >> x >> y;
    vector<ll> points(n);
    for(int i=0; i<n; i++)
    {
        cin >> points[i];
    }

    sort(all(points));
    ll ans = 0, r = 1;
    for(ll l=0; l<n-1; l++)
    {
        r = max(l + 1, r);
        while(r < n && !ck(points[l], points[r])) ++r;
        ans += max(0LL, n - r);
        //cout << l << " " << r << "\n";
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}

