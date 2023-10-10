#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

string S;

void solve()
{
    getline(cin, S);
    ll ret = 0;
    for(int i=0; i<sz(S); i++)
    {
        if (S[i] >= '0' && S[i] <= '9')
        {
            ret += (S[i] - '0');
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("TOTAL.INP", "r", stdin);
    freopen("TOTAL.OUT", "w", stdout);
    solve();
    return 0;
}
