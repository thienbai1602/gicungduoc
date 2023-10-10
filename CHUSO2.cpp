#include    <bits/stdc++.h>
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

ll p;

string num_to_string(ll X)
{
    string ans;
    while(X > 0)
    {
        ans = (char)(X % 10 + '0') + ans;
        X /= 10;
    }
    return ans;
}

void solve()
{
    cin >> p;
    vector<ll> pw(16, 1);
    for(int i=1; i<16; i++)
    {
        pw[i] = pw[i - 1] * 10;
    }

    int cnt = 1;
    while(p - 9 * cnt * pw[cnt - 1] > 0)
    {
        p -= 9 * cnt * pw[cnt - 1];
        ++cnt;
    }

    ll x = pw[cnt - 1] + p / cnt - 1;
    p %= cnt;
    if (p == 0)
    {
        cout << x % 10;
    } else
    {
        ++x;
        string num = num_to_string(x);
        cout << num[p - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
