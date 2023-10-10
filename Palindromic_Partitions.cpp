#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e6 + 66;
const int base  = 311;
const ll MOD = 1e9 + 7;

int tc;
string T;
ll hsh[mxN], pw[mxN];

ll getHash(int l, int r)
{
    return (hsh[r] - hsh[l - 1] * pw[r - l + 1] + MOD * MOD) % MOD;
}

void solve()
{
    cin >> T;
    hsh[0] = 0;
    for(int i=0; i<sz(T); i++)
    {
        hsh[i + 1] = (hsh[i] * base + (T[i] - 'a' + 1)) % MOD;
    }

    int suf = sz(T), pref = 1, ret = 0, ln;
    for(ln=1; ln<=sz(T) && ln < suf; ln++)
    {
        int sz = ln - pref + 1;
        //cout << pref << " " << suf << " " << sz << "\n";
        if (getHash(pref, ln) == getHash(suf - sz + 1, suf))
        {
            //cout << pref << " " << suf << " " << ln << "\n";
            suf -= sz;
            pref = ln + 1;
            ret += 2;
        }
    }
    cout << ret + (ln == suf) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    pw[0] = 1;
    for(int i=1; i<=mxN; i++)
    {
        pw[i] = (pw[i - 1] * base) % MOD;
    }
    cin >> tc;
    while(tc--) solve();
    return 0;
}
