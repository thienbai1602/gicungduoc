#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

ll N;
vector<ll> p;
bool isPrime[mxN];

void sieve()
{
    memset(isPrime, false, sizeof(isPrime));
    for(int i=2; i*i<=(ll)1e6; i++)
    {
        if (!isPrime[i])
        {
            for(int j=i*i; j<=(ll)1e6; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }

    for(int x=2; x<=(ll)1e6; x++)
    {
        if (!isPrime[x]) p.pb(x);
    }
}

void solve()
{
    cin >> N;
    cout << upper_bound(all(p), (ll)sqrt(N)) - p.begin();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    sieve(); solve();
    return 0;
}


