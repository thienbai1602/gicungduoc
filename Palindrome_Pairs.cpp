#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e5 + 66;

int n;
ll a[mxN];
unordered_map<ll, ll> ma;

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string S;
        cin >> S;
        ll x = 0;
        for(int i=0; i<sz(S); i++)
        {
            ll tp = (S[i] - 'a');
            x ^= (1 << tp);
        }
        a[i] = x;
    }

    ll ret = 0;
    for(int i=0; i<n; i++)
    {
        ret += ma[a[i]];
        for(ll mask=0; mask<26; mask++)
        {
            ret += ma[a[i] ^ (1 << mask)];
        }
        ++ma[a[i]];
        //cout << ret << "\n";
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
