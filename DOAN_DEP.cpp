#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e18;
const int mxN = 1e6 + 66;

int n;
bool isPrime[mxN];
ll a[mxN], pref[mxN];

void sieve()
{
    memset(isPrime, false, sizeof(isPrime));
    isPrime[0] = isPrime[1] = true;
    for(int i=2; i*i<=1000001; i++)
    {
        if (!isPrime[i])
        {
            for(int j=i*i; j<=1000001; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }
}

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    ll mi = pref[1], ans = -INF;
    for(int i=1; i<=n; i++)
    {
        if (!isPrime[i])
        {
            ans = max(ans, pref[i] - mi);
        }

        if (!isPrime[i + 1])
        {
            mi = min(mi, pref[i]);
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
