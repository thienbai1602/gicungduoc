#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

string S;
int n, cnt[35];

void solve()
{
    cin >> S;
    n = sz(S);
    for(int i=0; i<n; i++)
    {
        ++cnt[S[i] - 'a'];
    }

    int mx = 0;
    for(int i=0; i<26; i++)
    {
        if (mx < cnt[i]) mx = max(mx, cnt[i]);
    }

    for(int i=0; i<26; i++)
    {
        if (mx == cnt[i]) cout << (char)(i + 'a') << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("TKT.INP", "r", stdin);
    //freopen("TKT.OUT", "w", stdout);
    solve();
    return 0;
}
