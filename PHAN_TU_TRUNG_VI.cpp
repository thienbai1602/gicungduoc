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
const ll MOD = 65536;
const int mxN = 1e6 + 66;

multiset<ll> low, up;
int tc, n, seed, mul, add, K;

void ins(ll x)
{
    ll val = *low.rbegin();
    if (x > val)
    {
        up.insert(x);
        if (sz(up) > K / 2)
        {
            low.insert(*up.begin());
            up.erase(up.find(*up.begin()));
        }
    } else
    {
        low.insert(x);
        if (sz(low) > (K + 1) / 2)
        {
            up.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void er(ll x)
{
    if (up.find(x) != up.end()) up.erase(up.find(x));
     else low.erase(low.find(x));
    if (low.empty())
    {
        low.insert(*up.begin());
        up.erase(up.find(*up.begin()));
    }
}

ll solve()
{
    cin >> seed >> mul >> add >> n >> K;
    vector<ll> a(n);
    a[0] = seed;
    for(int i=1; i<n; i++)
    {
        a[i] = (a[i - 1] * mul + add) % MOD;
    }

    low.clear(), up.clear();
    low.insert(a[0]);
    for(int i=1; i<K-1; i++)
    {
        ins(a[i]);
    }

    ll ans = 0;
    for(int i=K-1; i<n; i++)
    {
        ins(a[i]);
        ans += *low.rbegin();
        er(a[i - K + 1]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> tc;
    for(int i=0; i<tc; i++)
    {
        cout << "Case #" << i + 1 << ": " << solve() << "\n";
    }
    return 0;
}
