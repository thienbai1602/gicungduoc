#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6 + 66;

int N, isPrime[mxN];

void sieve()
{
    for(int i=2; i<=(ll)1e6; i++)
    {
        isPrime[i] = i;
    }

    for(int i=2; i*i<=(ll)1e6; i++)
    {
        if (isPrime[i] == i)
        {
            for(int j=i*i; j<=(ll)1e6; j+=i)
            {
                isPrime[j] = i;
            }
        }
    }
}

void solve()
{
    cin >> N;
    ll ans = 0, div = 0;
    for(int x=2; x<=N; x++)
    {
        ll tp = x, sz = 0;
        while(tp > 1)
        {
            int p = isPrime[tp]; ++sz;
            while(tp % p == 0)
            {
                tp /= p;
            }
        }

        if (div <= sz)
        {
            ans = x;
            div = sz;
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
