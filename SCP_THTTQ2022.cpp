#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

int n, k, ma = -1;
vector<int> prime, store, cnt;

void sieve()
{
    prime = vector<int>(ma + 1);
    for(int i=1; i<=ma; i++)
    {
        prime[i] = i;
    }

    for(int i=2; i*i<=ma; i++)
    {
        if (prime[i] == i)
        {
            store.push_back(i);
            for(int j=i*i; j<=ma; j+=i)
            {
                prime[j] = i;
            }
        }
    }
}

ll pw(ll a, ll b)
{
    if (b == 0) return 1;
    if (b == 1) return (a % mod);
    ll t = pw(a, b / 2);
    t = ((t % mod) * (t % mod)) % mod;
    if (b % 2 == 0) return t % mod;
     else return ((a % mod) * (t % mod)) % mod;
}

void solve()
{
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        ma = max(ma, a[i]);
    }

    sieve();
    int X = a[k - 1];
    cnt = vector<int>(ma + 1, 0);
    for(int i=0; i<n; i++)
    {
        while(a[i] > 1)
        {
            int p = prime[a[i]];
            int ct = 0;
            while(a[i] % p == 0)
            {
                ct++;
                a[i] /= p;
            }
            cnt[p] = max(cnt[p], ct);
        }
    }


    while(X > 1)
    {
        int p = prime[X];
        while(X % p == 0)
        {
            cnt[p]--;
            X /= p;
        }
    }

    ll ret = 1;
    for(int& x : store)
    {
        if (cnt[x] > 1)
        {
            ret = (ret % mod * pw(x, cnt[x] / 2 * 2) % mod) % mod;
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
