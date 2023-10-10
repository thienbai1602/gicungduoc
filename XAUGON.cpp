#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

int n;
string S;

void solve()
{
    cin >> S;
    n = sz(S);

    string res = {S[0]};
    for(int i=1; i<n; i++)
    {
        if (S[i] != res[sz(res) - 1])
        {
            res.push_back(S[i]);
        }
    }

    for(int i=0; i<sz(res); i++)
    {
        cout << res[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("XAUGON.INP", "r", stdin);
    freopen("XAUGON.OUT", "w", stdout);
    solve();
    return 0;
}
