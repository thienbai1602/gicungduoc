#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int base = 311;
const int mxN = 1e6 + 66;

int n, m;
string S, T;
ll zero = 0, one = 0, pw[mxN][2], hsh[mxN][2], mod[2];

ii get(int st, int ed)
{
    ll res_1 = (hsh[ed + 1][0] - hsh[st][0] * pw[ed - st + 1][0] + mod[0] * mod[0]) % mod[0];
    ll res_2 = (hsh[ed + 1][1] - hsh[st][1] * pw[ed - st + 1][1] + mod[1] * mod[1]) % mod[1];
    return mp(res_1, res_2);
}

void solve()
{
    cin >> S >> T;
    n = sz(S), m = sz(T);

    for(int i=0; i<n; i++)
    {
        if (S[i] == '0') zero++;
         else one++;
    }

    mod[0] = 1e9 + 3, mod[1] = 1e9 + 7;
    pw[0][0] = pw[0][1] = 1;
    for(int ps=0; ps<2; ps++)
    {
        for(int i=1; i<=m; i++)
        {
            pw[i][ps] = pw[i - 1][ps] * base % mod[ps];
        }
    }

    hsh[0][0] = hsh[0][1] = 0;
    for(int ps=0; ps<2; ps++)
    {
        for(int i=0; i<m; i++)
        {
            hsh[i + 1][ps] = (hsh[i][ps] * base + (T[i] - 'a' + 1)) % mod[ps];
        }
    }

    if (one > zero)
    {
        swap(one, zero);
        for(int i=0; i<n; i++)
        {
            if (S[i] == '0') S[i] = '1';
             else S[i] = '0';
        }
    }

    ll ret = 0;
    for(int sz=1; sz<=m; sz++)
    {
        if (sz * zero >= m) break;
        if ((m - sz * zero) % one != 0) continue;

        int cur = 0;
        bool flat = true;
        int zl = sz, ol = (m - sz * zero) / one;
        ii hz = mp(-1, -1), ho = mp(-2, -2);
        for(char& c : S)
        {
            if (hz == ho)
            {
                flat = false;
                break;
            }

            if (c == '0')
            {
                ii tp = get(cur, cur + sz - 1);
                if (hz.fi == -1)
                {
                    hz = tp;
                } else
                {
                    if (hz != tp)
                    {
                        flat = false;
                        break;
                    }
                }
                cur += sz;
            } else
            {
                ii tp = get(cur, cur + ol - 1);
                if (ho.fi == -2)
                {
                    ho = tp;
                } else
                {
                    if (ho != tp)
                    {
                        flat = false;
                        break;
                    }
                }
                cur += ol;
            }
        }
        ret += (flat && (hz != ho));
    }
    cout << ret;;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
