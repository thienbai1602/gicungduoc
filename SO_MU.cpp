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
const int mxN = 1e7 + 66;

ll N;
vector<bool> isPrime(mxN, false);

ll pow(ll a, ll b)
{
    ll ret = 1;
    while(b)
    {
        if (b & 1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

void solve()
{
    cin >> N;
    if (N == 1)
    {
        cout << 0;
        return;
    }

    isPrime[0] = isPrime[1] = true;
    for(int i=2; i*i<=(int)1e7; i++)
    {
        if (!isPrime[i])
        {
            for(int j=i*i; j<=(int)1e7; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }

    vector<ll> p;
    for(int i=2; i<=(int)1e7; i++)
    {
        if (!isPrime[i]) p.pb(i);
    }

    ll mx = 0, cur = 1;
    vector<ii> store;
    for(ll &prime : p)
    {
        int ct = 0;
        while(N % prime == 0)
        {
            N /= prime;
            ++ct;
        }

        if (ct > 0)
        {
            cur *= prime;
            store.pb(mp(prime, ct));
            mx = __gcd(mx, (ll)ct);
        }
    }

    if (N > 1)
    {
        ll sq = (ll)sqrt(N);
        if (sq * sq == N)
        {
            cout << 1 << "\n" << (ll)sq * cur << " " << 2;
            return;
        }
        cout << 0;
        return;
    }

    bool ok = true;
    for(int i=0; i<sz(store); i++)
    {
        if (store[i].se % mx != 0)
        {
            ok = false;
            break;
        } else
        {
            store[i] = mp(pow(store[i].fi, store[i].se / mx), mx);
        }
    }

    if (!ok)
    {
        cout << 0;
    } else
    {
        ll nxt = 1, sl = store[0].se;
        for(auto [x, cnt] : store)
        {
            nxt *= x;
        }

        if (N > 1)
        {
            ll sq = (ll)sqrt(N);
            if (sq * sq == N)
            {
                if (sl == 2) cout << 1 << "\n" << (ll)sq * nxt << " " << 2;
                 else cout << 0;
                return;
            } else
            {
                cout << 0;
                return;
            }
        }

        vector<int> div;
        for(int d=1; d*d<=sl; d++)
        {
            if (sl % d == 0)
            {
                if (sl / d > 1) div.pb(d);
                if (sl / d != d)
                {
                    if (sl / (sl / d) > 1) div.pb(sl / d);
                }
            }
        }


        cout << sz(div) << "\n";
        sort(rall(div));
        for(auto &pw : div)
        {
            cout << (ll)pow(nxt, pw) << " " << (ll)sl / pw << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
