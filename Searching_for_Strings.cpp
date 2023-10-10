#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define mp make_pair
using namespace std;

const int mxN = 2e5 + 66;
const ll mod = 1e9 + 3;
const ll MOD = 1e9 + 7;

ll hashN[mxN][2], power[mxN][2];
int n, h, base = 311, cnt[305];
string N, H, nxt;
set<pair<ll, ll>> ms;

ll getHash(int st, int ed, int ps, ll M)
{
    return ((hashN[ed][ps] - hashN[st - 1][ps] * power[ed - st + 1][ps]) % M + M) % M;
}

void solve()
{
    cin >> H >> N;
    n = sz(N), h = sz(H);

    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<h; i++)
    {
        cnt[H[i]]++;
        if (i < h - 1) cnt[N[i]]--;
    }

    power[0][0] =  power[0][1] = 1;
    for(int i=1; i<=n; i++)
    {
        power[i][0] = (power[i - 1][0] * base) % mod;
        power[i][1] = (power[i - 1][1] * base) % MOD;
    }

    hashN[0][0] = hashN[0][1] = 0;
    for(int i=1; i<=n; i++)
    {
        hashN[i][0] = (hashN[i - 1][0] * base + N[i - 1]) % mod;
        hashN[i][1] = (hashN[i - 1][1] * base + N[i - 1]) % MOD;
    }

    ll ret = 0;
    for(int i=h-1; i<n; i++)
    {
        cnt[N[i]]--;
        if (i >= h)
        {
            cnt[N[i - h]]++;
        }

        int ct = 0;
        for(char r='a'; r<='z'; r++)
        {
            ct += cnt[r] == 0;
        }

        if (ct == 26)
        {
            ll nxt = getHash(i - h + 2, i + 1, 0, mod) % mod;
            ll tp = getHash(i - h + 2, i + 1, 1, MOD) % MOD;
            ms.insert(mp(nxt, tp));
        }
    }
    cout << sz(ms);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
