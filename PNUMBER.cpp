#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll L, R;

void solve()
{
    cin >> L >> R;
    vector<bool> isPrime(R - L + 1, true);
    for(ll i=2; i*i<=R; i++)
    {
        for(ll j=max(i*i, (L + i - 1) / i * i); j<=R; j+=i)
        {
            isPrime[j - L] = false;
        }
    }

    if (1 >= L) isPrime[1 - L] = false;
    for(ll x=L; x<=R; x++)
    {
        if (isPrime[x - L])
        {
            cout << x << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
