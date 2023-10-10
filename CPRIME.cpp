#include    <bits/stdc++.h>
#define ll long long
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
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int N, isPrime[mxN];
vector<ii> Q;
bool p[mxN];

void sieve()
{
    set0(isPrime);
    isPrime[0] = isPrime[1] = -1;
    for(int i=2; i<=(ll)1e6; i++)
    {
        if (!isPrime[i])
        {
            for(int j=i; j<=(ll)1e6; j+=i)
            {
                isPrime[j] = i;
            }
        }
    }

    memset(p, false, sizeof(p));
    for(int x=1; x<=(ll)1e6; x++)
    {
        ll nxt = x, cnt = 1;
        while(nxt > 1)
        {
            int prime = isPrime[nxt], ct = 0;
            while(nxt % prime == 0)
            {
                nxt /= prime;
                ++ct;
            }
            cnt *= (ct + 1);
        }
        p[x] = (isPrime[cnt] == cnt);
    }
}

void sub1()
{
    vector<int> pref((ll)1e6 + 66, 0);
    for(int i=1; i<=(ll)1e6; i++)
    {
        pref[i] = pref[i - 1] + p[i];
    }

    for(int i=0; i<N; i++)
    {
        ll x = Q[i].fi, y = Q[i].se;
        cout << pref[y] - pref[x - 1] << "\n";
    }
}

void sub2()
{
    vector<ll> prime;
    for(int i=2; i<=(ll)1e6; i++)
    {
        if (isPrime[i] == i) prime.pb(i);
    }

    vector<ll> ans;
    for(auto x : prime)
    {
        ll tp = 1;
        for(int k=1; tp*x<=(ll)1e12; k++)
        {
            tp *= x;
            if (isPrime[k + 1] == k+1) ans.pb(tp);
        }
    }

    sort(all(ans));
    for(int i=0; i<N; i++)
    {
        ll x = Q[i].fi, y = Q[i].se;
        int posL = lower_bound(all(ans), x) - ans.begin();
        int posR = upper_bound(all(ans), y) - ans.begin();
        cout << posR - posL << "\n";
    }
}

void solve()
{
    cin >> N;
    ll mx = 0;
    for(int i=0; i<N; i++)
    {
        ll a, b;
        cin >> a >> b;
        Q.pb(mp(a, b));
        mx = max(mx, b);
    }
    if (mx <= (ll)1e6) sub1();
     else sub2();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    sieve(); solve();
    return 0;
}
