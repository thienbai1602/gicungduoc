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

bool isPrime[mxN * 2];
int tc, N, S[mxN * 2];

void sieve()
{
    memset(isPrime, false, sizeof(isPrime));
    isPrime[0] = isPrime[1] = true;
    for(int i=2; i*i<=(int)2e6; i++)
    {
        if (!isPrime[i])
        {
            for(int j=i*i; j<=(int)2e6; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }

    set0(S);
    for(int i=1; i<=(int)2e6; i++)
    {
        S[i] = S[i - 1] + (!isPrime[i]);
    }
}

void solve()
{
    cin >> N;
    ll ret = 0;
    for(int i=1; i<=N; i++)
    {
        ret += 1LL * (S[i + N] - S[i + (i == 1)]) * (N - (S[i + N] - S[i]) - (i != 1));
    }
    cout << 1LL * N * (N - 1) * (N - 2) / 6 - ret / 2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif //SKY
    cin >> tc; sieve();
    while(tc--) solve();
    return 0;
}
