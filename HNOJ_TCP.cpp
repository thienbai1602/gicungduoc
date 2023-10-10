#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int N, isPrime[mxN];
ll cnt[mxN];

void sieve()
{
    for(int i=1; i<=100006; i++)
    {
        isPrime[i] = i;
    }

    for(int i=2; i*i<=100006; i++)
    {
        if (isPrime[i] == i)
        {
            for(int j=i*i; j<=100006; j+=i)
            {
                isPrime[j] = i;
            }
        }
    }
}

int core(int X)
{
    int ans = 1;
    while(X > 1)
    {
        int p = isPrime[X], ct = 0;
        while(X % p == 0)
        {
            X /= p;
            ++ct;
        }
        if (ct & 1) ans *= p;
    }
    return ans;
}

void solve()
{
    cin >> N;
    ll ret = 0;
    memset(cnt, 0, sizeof(cnt));
    for(int x=1; x<=N; x++)
    {
        int nxt = core(x);
        ret += 2 * cnt[nxt];
        ++cnt[nxt];
    }
    cout << ret + N;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    sieve(); solve();
    return 0;
}
