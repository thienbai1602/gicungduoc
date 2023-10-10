#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e6 + 66;
const int base = 311;
const ll MOD = 1e9 + 7;

string S, T;
ll hsh, hashS[mxN], pw[mxN];

void solve()
{
    cin >> S >> T;
    pw[0] = 1;
    for(int i=0; i<sz(S); i++)
    {
        pw[i + 1] = pw[i] * base % MOD;
    }

    hsh = 0;
    for(int i=0; i<sz(T); i++)
    {
        hsh = (hsh + (T[i] - 'a' + 1) * pw[i]) % MOD;
    }
    hsh = (hsh * pw[sz(S) - sz(T)]) % MOD;

    hashS[0] = 0;
    vector<char> st;
    for(int i=0, cur=1; i<sz(S); i++, cur++)
    {
        st.push_back(S[i]);
        hashS[cur] = (hashS[cur - 1] + (S[i] - 'a' + 1) * pw[cur - 1]) % MOD;
        if (cur >= sz(T))
        {
            ll tp = ((hashS[cur] - hashS[cur - sz(T)]) + MOD * MOD) % MOD * pw[sz(S) - cur] % MOD;
            if (tp == hsh)
            {
                cur -= sz(T);
                for(int j=0; j<sz(T); j++)
                {
                    st.pop_back();
                }
            }
        }
    }
    for(char c : st) cout << c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    solve();
    return 0;
}
