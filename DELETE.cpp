#include    <bits/stdc++.h>
#define ll long long
using namespace std;

string S;

void solve()
{
    cin >> S;
    string ret = "";
    for(int i=0; i<(int)S.size(); i++)
    {
        if (S[i] != '0' && S[i] != '1')
        {
            ret = ret + S[i];
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("DELETE.INP", "r", stdin);
    freopen("DELETE.OUT", "w", stdout);
    solve();
    return 0;
}
