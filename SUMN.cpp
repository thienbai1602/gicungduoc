#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

string S;

void solve()
{
    cin >> S;
    int s = 0;
    for(int i=0; i<sz(S); i++)
    {
        s = (s + S[i] - '0');
    }
    cout << s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("SUMN.INP", "r", stdin);
    freopen("SUMN.OUT", "w", stdout);
    solve();
    return 0;
}
