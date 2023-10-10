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

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 5e6 + 66;

int N, co[mxN], isPrime[mxN], ct[mxN];

void sieve()
{
    for(int i=1; i<=(ll)5e6; i++)
    {
        isPrime[i] = i;
    }

    for(int i=2; i*i<=(ll)5e6; i++)
    {
        if (isPrime[i] == i)
        {
            for(int j=i*i; j<=(ll)5e6; j+=i)
            {
                isPrime[j] = i;
            }
        }
    }
}

ll ck(ll n)
{
    return n * (n - 1) * (n - 2) / 6;
}

void solve()
{
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        co[i] = 1;
    }

    for(int i=1; i<=N; i++)
    {
        int x = i;
        while(x > 1)
        {
            int p = isPrime[x], cnt = 0;
            while(x % p == 0)
            {
                x /= p;
                ++cnt;
            }
            if (cnt & 1) co[i] *=  p;
        }
        ++ct[co[i]];
    }

    ll ans = 0;
    for(int i=1; i<=N; i++)
    {
        if (ct[i] > 2)
        {
            ans += ck(ct[i]);
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    sieve(); solve();
    return 0;
}
