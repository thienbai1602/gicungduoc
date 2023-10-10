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
const int mxN = 2e5 + 66;

int nS;
string S;

void solve()
{
    cin >> S;
    nS = sz(S);
    vector<vector<int>> cnt(26);
    for(int i=0; i<nS; i++)
    {
        char chr = S[i];
        cnt[chr - 'a'].pb(i);
    }

    int ans = 1;
    for(int len=2; len<=n; len++)
    {
        for(int chr=0; chr<26; chr++)
        {

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
