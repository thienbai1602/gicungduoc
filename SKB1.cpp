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
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 3e6 + 66;

int tc, N;
vector<int> prime;
bool isPrime[mxN];

void sieve()
{
    memset(isPrime, false, sizeof(isPrime));
    isPrime[0] = isPrime[1] = true;
    for(int i=2; i*i<=(int)3e6; i++)
    {
        if (!isPrime[i])
        {
            for(int j=i*i; j<=(int)3e6; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }

    for(int i=2; i<=(int)3e6; i++)
    {
        if (!isPrime[i]) prime.pb(i);
    }
}

void solve()
{
    cin >> N;
    vector<vector<int>> store(N + 1, vector<int>());
    for(int i=1; i<=N; i++)
    {
        for(int &p : prime)
        {
            if (i * 2 >= p) continue;
            if (p > N * 3) break;
            store[i].pb(p);
        }
    }

    ll ans = 0;
    for(int i=1; i<=N; i++)
    {
        for(int &x : store[i])
        {
            int j = x - i;
            if (j > N) break;
            for(int &y : store[j])
            {
                int k = y - j;
                if (k > N) break;
                if (!isPrime[i + k]) ++ans;
            }
        }
    }

    for(int i=1; i<=N; i++)
    {
        for(int j=i+1; j<=N; j++)
        {
            if (!isPrime[i + j]) continue;
            vector<int> cnt(N + 1, 0);
            for(int &x : store[i])
            {
                if (x - i <= N) cnt[x - i]++;
                 else break;
            }

            for(int &y : store[j])
            {
                if (y - j <= N) cnt[y - j]++;
                 else break;
            }

            for(int k=j+1; k<=N; k++)
            {
                ans += !cnt[k];
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    sieve(); cin >> tc;
    while(tc--) solve();
    return 0;
}
