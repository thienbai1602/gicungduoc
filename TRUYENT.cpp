#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;

const int base = 311;
const int mxN = 100066;

int n;
string T;
ll hsh[mxN][2], pw[mxN][2], mod[2];

ii getHash(int i, int j)
{
    ll A = (hsh[j][0] - hsh[i - 1][0] * pw[j - i + 1][0] + mod[0] * mod[0]) % mod[0];
    ll B = (hsh[j][1] - hsh[i - 1][1] * pw[j - i + 1][1] + mod[1] * mod[1]) % mod[1];
    return make_pair(A, B);
}

void solve()
{
    cin >> n >> T;
    mod[0] = 1e9 + 3, mod[1] = 1e9 + 7;
    pw[0][0] = pw[0][1] = 1;
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
            hsh[i + 1][ps] = (hsh[i][ps] * base + T[i]) % mod[ps];
        }
    }

    for(int cur=1; cur<=n; cur++)
    {
        bool flat = true;
        int st = cur + 1, ed = cur * 2;
        while(st <= n)
        {
            ii c = getHash(st, min(ed, n));
            ii tp = getHash(1, min(cur, n - st + 1));
            if (c != tp)
            {
                flat = false;
                break;
            }
            st = ed + 1, ed = ed + cur;
        }

        if (flat)
        {
            cout << cur;
            break;
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
