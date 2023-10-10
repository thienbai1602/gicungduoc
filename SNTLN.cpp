#include    <bits/stdc++.h>
//#define SKY
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

int n;
string S;
bool isPrime[mxN];

void sieve()
{
    memset(isPrime, false, sizeof(isPrime));
    isPrime[0] = isPrime[1] = true;
    for(int i=2; i*i<=(int)1e5; i++)
    {
        if (!isPrime[i])
        {
            for(int j=i*i; j<=(int)1e5; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }
}

void solve()
{
    cin >> S;
    n = sz(S);
    ll ans = 0;
    for(int i=0; i<sz(S); i++)
    {
        if (S[i] >= '0' && S[i] <= '9')
        {
            ll nxt = 0;
            for(int j=i; j<sz(S); j++)
            {
                if (S[j] >= '0' && S[j] <= '9')
                {
                    nxt = nxt * 10 + (int)(S[j] - '0');
                    if (nxt > (int)1e5) break;
                    if (!isPrime[nxt]) ans = max(nxt, ans);
                } else break;
            }
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif //SKY
    sieve(); solve();
    return 0;
}
