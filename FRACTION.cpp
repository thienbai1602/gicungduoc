#include    <bits/stdc++.h>
#define ll long long
#define set0(x) memset(x, 0, sizeof(x))
using namespace std;

const int mxN = 1e6 + 66;

int tc, n;
int a[mxN], b[mxN], isPrime[mxN];

void sieve()
{
    for(int i=1; i<=1e6; i++)
    {
        isPrime[i] = i;
    }

    for(int i=2; i*i<=1e6; i++)
    {
        if (isPrime[i] == i)
        {
            for(int j=i*i; j<=1e6; j+=i)
            {
                isPrime[j] = i;
            }
        }
    }
}

void solve()
{
    cin >> n;
    set0(a), set0(b);
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        while(x > 1)
        {
            int p = isPrime[x];
            while(x % p == 0)
            {
                x /= p;
                a[p]++;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        while(x > 1)
        {
            int p = isPrime[x];
            while(x % p == 0)
            {
                x /= p;
                ++b[p];
            }
        }
    }

    bool flat = true;
    for(int i=2; i<=1e6; i++)
    {
        if(i == 2 || i == 5) continue;
        b[i] -= a[i];
        flat = !(b[i] > 0);
        if (!flat) break;
    }
    cout << (flat ? "finite\n" : "repeating\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    sieve();
    cin >> tc;
    while(tc--) solve();
    return 0;
}
