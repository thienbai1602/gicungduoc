/*#include    <bits/stdc++.h>
#define ll long long
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

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

int tc;
ll N, M, K, mod;

ll pw(ll a, ll b, ll mod)
{
    ll ans = 1;
    while(b)
    {
        if (b & 1) ans = ((ans % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
        b >>= 1;
    }
    return ans;
}

ll ck(ll k, ll n, ll mod)
{
    ll ret = 1;
    for(ll x=n-k+1, div=k; x<=n; x++)
    {
        ret *= x;
        if (ret % div == 0)
        {
            ret /= div--;
        }
        ret %= mod;
    }
    return ret;
}

ll frac(ll x, ll y, ll mod)
{
    ll ans = 1;
    for(; y>0; x++, y--)
    {
        ans = ((ans % mod) * (x % mod)) % mod;
    }
    return ans;
}

void solve()
{
    cin >> K >> M >> N >> mod;
    M = abs(M), N = abs(N);

    if (K < M + N || (K - M - N ) & 1)
    {
        //cout << "0\n";
    } else
    {
        if (M > N) swap(M, N);
        //cout << ((ck(M, M + N, mod) % mod) * (pw(4, (K - M - N) / 2, mod) % mod) * ((frac(M + N + 1, K - N - M, mod)) % mod)) % mod << "\n";
    }

    cout << (K + M - N >> 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> tc;
    while(tc--) solve();
    return 0;
}*/
#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define __unique(V) (V).resize(unique((V).begin(),(V).end())-(V).begin())
#define cntbit(X)   __builtin_popcount((X))
#define bit(S,i) (((S)>>(i))&1)
#define PI	acos(-1)
#define fi  first
#define se  second
#define LL  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define eb  emplace_back
#define TASK "countk"
using namespace std;
const int maxn = 1e5 + 5;
int k,m,n,mod,w[maxn];
bool pr[maxn];
///--------------------------
void    readf(){
    cin >> k >> m >> n >> mod;
}
///--------------------------
void	sieve(){
    memset(pr,1,sizeof(pr));
    pr[1] = pr[0] = 0;
    for(int i = 2; i * i < maxn; ++i)
		if (pr[i]) for(int j = i * i; j < maxn; j += i) pr[j] = 0;
}
///--------------------------
void	build(int N,int t){
    for(int i = 2 ; i <= N; ++i) if (pr[i]){
		int tmp = N;
		while (tmp > 0) w[i] += t * (tmp/=i);
    }
}
///--------------------------
int	pw(int a,int b){
    int tmp = 1;
    for(  ; b ; a = 1LL * a * a % mod, b >>= 1)
		if (b & 1) tmp = 1LL * tmp * a % mod;
	return tmp;
}
///--------------------------
int	C(int K,int N){
    memset(w,0,sizeof(w));
    build(N,1); build(K,-1); build(N - K,-1);
    int ans = 1;
    for(int i = 2; i <= N; ++i) if (pr[i])
		ans = 1LL * ans * pw(i,w[i]) % mod;
	return ans;
}
///--------------------------
void    solve(){
	if ((k + m + n) % 2 == 1 || k < abs(m) + abs(n)){
		cout << 0 << '\n';
		return;
    }
    int ans = C(k + m - n >> 1, k) * 1LL * C(k - m - n >> 1,k) % mod;
    cout << (k + m - n >> 1) << " " << (k - m - n >> 1) << "\n";
    //cout << ans << '\n';
}
///--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifdef TLH2203
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    #endif // TLH2203
    sieve();
    int T;
    cin >> T;
    while (T--){
		readf();
		solve();
    }
}
