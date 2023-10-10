#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e6 + 55;
const int base = 311;

int n;
string T;
ll hashT[mxN][2], pw[mxN][2], mod[2];

ll getHash(int ps, int st, int ed)
{
    return (hashT[ed + 1][ps] - hashT[st][ps] * pw[ed - st + 1][ps] + mod[ps] * mod[ps]) % mod[ps];
}

void solve()
{
    cin >> T;
    n = sz(T);

    mod[0] = 1e9 + 3, mod[1] = 1e9 + 7;
    pw[0][0] = pw[0][1] = 1;
    for(int ps=0; ps<1; ps++)
    {
        for(int i=1; i<=n; i++)
        {
            pw[i][ps] = (pw[i - 1][ps] * base) % mod[ps];
        }
    }

    hashT[0][0] = hashT[0][1] = 0;
    for(int ps=0; ps<1; ps++)
    {
        for(int i=1; i<=n; i++)
        {
            hashT[i][ps] = (hashT[i - 1][ps] * base + T[i - 1]) % mod[ps];
        }
    }

    for(int i=0; i<n; i++)
    {
        int cur = 0;
        bool check = true;
        while(cur < n)
        {
            int sz = min(i + 1, n - cur);
            for(int ps=0; ps<1; ps++)
            {
                check &= (getHash(ps, 0, sz - 1) == getHash(ps, cur, cur + sz - 1));
            }
            cur += sz;

            if (!check) break;
        }

        if (check)
        {
            cout << i + 1 << " ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
