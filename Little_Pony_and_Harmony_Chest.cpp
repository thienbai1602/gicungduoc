#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;

const int mxN = 106;
const int mxA = 60;
const int mxP = 17;
const ll INF = 1e17;

int n, a[mxN], trav[mxN][1 << mxP];
ll prime_k[mxA], dp[mxN][1 << mxP];
vector<int> copri = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    fill(prime_k, prime_k + mxA, 0);
    for(int p=0; p<sz(copri); p++)
    {
        for(int x=1; x<=mxA; x++)
        {
            if (x % copri[p] == 0)
            {
                prime_k[x] |= (1 << p);
            }
        }
    }

    for(int i=0; i<=n; i++)
    {
        fill(dp[i], dp[i] + (1 << mxP), INF);
    }

    dp[0][0] = 0;
    for(int i=0; i<n; i++)
    {
        for(int mask=0; mask<(1 << mxP); mask++)
        {
            for(int k=1; k<=mxA; k++)
            {
                if (dp[i][mask] == INF || (mask & prime_k[k])) continue;
                int new_mask = mask | prime_k[k];
                if (dp[i + 1][new_mask] > dp[i][mask] + abs(a[i] - k))
                {
                    dp[i + 1][new_mask] = dp[i][mask] + abs(a[i] - k);
                    trav[i + 1][new_mask] = k;
                }
            }
        }
    }

    ll ans = INF, ans_mask = -1;
    for(int mask=0; mask<(1 << mxP); mask++)
    {
        if (ans > dp[n][mask])
        {
            ans = dp[n][mask];
            ans_mask = mask;
        }
    }

    vector<int> res;
    for(int id=n, mask=ans_mask; id>0; id--)
    {
        res.pb(trav[id][mask]);
        mask ^= prime_k[trav[id][mask]];
    }

    reverse(all(res));
    for(int& x : res) cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
