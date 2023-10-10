#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int tc;
ll A, B;
vector<int> v = {2, 7, 61};

ll pw(ll a, ll b, ll m)
{
    if (b == 0) return 1;
    if (b == 1) return (a % m);
    ll t = pw(a, b/2, m);
    t = ((t % m) * (t % m)) % m;
    if (b % 2) return ((a % m) * (t % m)) % m;
     else return t % m;
}

bool check_composite(ll n, ll a, ll d, ll s)
{
    ll x = pw(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for(int r=0; r<s; r++)
    {
        x = ((x % n) * (x % n)) % n;
        if (x == n - 1) return false;
    }
    return true;
}

bool miller(ll n)
{
    if (n <= 4)
    {
        return (n == 2 || n == 3);
    }

    ll s = 0, d = n - 1;
    while(d % 2 == 0)
    {
        d >>= 1;
        s++;
    }

    for(int& a : v)
    {
        if (n == a) return true;
        if (check_composite(n, a, d, s)) return false;
    }
    return true;
}

void solve()
{
    cin >> A >> B;
    for(ll x=A; x<=B; x++)
    {
        if (miller(x)) cout << x << "\n";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
