#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 2e6 + 66;

int n, K;
bool isPrime[mxN];

void sieve()
{
    memset(isPrime, false, sizeof(isPrime));
    isPrime[0] = isPrime[1] = true;
    for(int i=2; i*i<=2e6; i++)
    {
        if (!isPrime[i])
        {
            for(int j=i*i; j<=2e6; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }
}

void solve()
{
    cin >> n >> K;
    int ret = 0;
    for(int i=K; i<=n; i++)
    {
        if (!isPrime[i] && !isPrime[i - K]) ret++;
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("TWINS.INP", "r", stdin);
    freopen("TWINS.OUT", "w", stdout);
    sieve(); solve();
    return 0;
}
