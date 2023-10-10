#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

int n;
vector<bool> isPrime(2e7 + 7, false);

void sieve()
{
    isPrime[0] = isPrime[1] = true;
    for(ll i=2; i<=20000000; i++)
    {
        if (!isPrime[i])
        {
            for(ll j=i*i; j<=20000000; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }
}

void solve()
{
    cin >> n;
    ll ret = 0;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        ll tp = (ll)sqrt(x);
        if (tp * tp == x)
        {
            ret += !isPrime[tp];
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    sieve(); solve();
    return 0;
}
