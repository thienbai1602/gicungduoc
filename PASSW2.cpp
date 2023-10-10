#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int base = 311;
const int mxN = 1e3 + 66;

int n;
string S;
ll hsh[mxN][2], hsh_rev[mxN][2], pw[mxN][2], mod[2];

ii getHash(int st, int ed)
{
    ll A = (hsh[ed + 1][0] - hsh[st][0] * pw[ed - st + 1][0] + mod[0] * mod[0]) % mod[0];
    ll B = (hsh[ed + 1][1] - hsh[st][1] * pw[ed - st + 1][1] + mod[1] * mod[1]) % mod[1];
    return mp(A, B);
}

ii getHash_rev(int st, int ed)
{
    ll A = (hsh_rev[st + 1][0] - hsh_rev[ed + 2][0] * pw[ed - st + 1][0] + mod[0] * mod[0]) % mod[0];
    ll B = (hsh_rev[st + 1][1] - hsh_rev[ed + 2][1] * pw[ed - st + 1][1] + mod[1] * mod[1]) % mod[1];
    return mp(A, B);
}

void solve()
{
    cin >> S;
    n = sz(S);

    pw[0][0] = pw[0][1] = 1;
    mod[0] = 1e9 + 3, mod[1] = 1e9 + 7;
    for(int i=1; i<=n; i++)
    {
        for(int ps=0; ps<2; ps++)
        {
            pw[i][ps] = pw[i - 1][ps] * base % mod[ps];
        }
    }

    hsh[0][0] = hsh[0][1] = 0;
    for(int i=0; i<n; i++)
    {
        for(int ps=0; ps<2; ps++)
        {
            hsh[i + 1][ps] = (hsh[i][ps] * base + S[i]) % mod[ps];
        }
    }

    hsh_rev[n + 1][0] = hsh_rev[n + 1][1] = 0;
    for(int i=n-1; i>=0; i--)
    {
        for(int ps=0; ps<2; ps++)
        {
            hsh_rev[i + 1][ps] = (hsh_rev[i + 2][ps] * base + S[i]) % mod[ps];
        }
    }

    ll ret = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if (getHash(i, j) == getHash_rev(i, j))
            {
                ret = max(ret, 1LL * (j - i + 1));
            }
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
