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

int N;

void solve()
{
    cin >> N;
    vector<int> cnt(N + 1, 0);
    for(int r=1; r<=N; r++)
    {
        for(int c=1; c<=N; c++)
        {
            char chr;
            cin >> chr;
            cnt[c] += (chr == 'X');
        }
    }

    int mx = 0;
    vector<int> ans;
    for(int i=1; i<=N; i++)
    {
        mx = max(mx, cnt[i]);
    }

    for(int i=1; i<=N; i++)
    {
        if (mx == cnt[i]) ans.pb(i);
    }

    cout << sz(ans) << " " << mx << "\n";
    for(int &x : ans) cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif //SKY
    solve();
    return 0;
}
