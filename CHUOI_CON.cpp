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
const int mxN = 2e3 + 66;

string S;
int sz, dp[mxN][mxN];

void truy_vet(int idx)
{
    int l = idx, r = idx;
    string ans, rans;
    if (dp[idx][idx] & 1)
    {
        rans = S[idx - 1];
        --l, ++r;
    }

    while(l > 0 && r <= sz)
    {
        if (S[l - 1] == S[r - 1])
        {
            ans = S[l - 1] + ans;
            rans = rans + S[l - 1];
            --l, ++r;
            continue;
        }

        if (dp[l][r] == dp[l - 1][r]) --l;
         else ++r;
    }
    cout << ans << rans;
}

void solve()
{
    cin >> S;
    sz = sz(S);
    set0(dp);
    for(int i=1; i<=sz; i++)
    {
        for(int j=sz; j>=i; j--)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
            if (S[i - 1] == S[j - 1])
            {
                dp[i][j] = max(dp[i - 1][j + 1] + 1 + (i != j), dp[i][j]);
            }
        }
    }

    int pos = 0;
    for(int i=1; i<=sz; i++)
    {
        if (dp[pos][pos] < dp[i][i])
        {
            pos = i;
        }
    }
    truy_vet(pos);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}

