#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e4 + 66;

ll N;
int isPrime[mxN], cnt[mxN];

void sieve()
{
    for(int i=2; i<=10006; i++)
    {
        isPrime[i] = i;
    }

    for(int i=2; i*i<=10006; i++)
    {
        if (isPrime[i] == i)
        {
            for(int j=i*i; j<=10006; j+=i)
            {
                isPrime[j] = i;
            }
        }
    }
}

void solve()
{
    cin >> N;
    memset(cnt, 0, sizeof(cnt));
    for(ll x=1; x<=N; x++)
    {
        ll nxt = x;
        while(nxt > 1)
        {
            int p = isPrime[nxt];
            while(nxt % p == 0)
            {
                ++cnt[p];
                nxt /= p;
            }
        }
    }

    ll ans = 1;
    cnt[2] -= cnt[5], cnt[5] = 0;
    for(int i=2; i<=N; i++)
    {
        if (cnt[i])
        {
            for(int j=0; j<cnt[i]; j++)
            {
                ans = (ans * i) % 10;
            }
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    sieve(); solve();
    return 0;
}
