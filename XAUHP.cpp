#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

int tc;

void solve()
{
    string S, Rev;
    cin >> S;
    for(int i=sz(S)-1; i>=0; i--)
    {
        Rev = Rev + S[i];
    }

    for(int i=1; i<sz(S); i++)
    {
        if (abs(S[i] - S[i - 1]) != abs(Rev[i] - Rev[i - 1]))
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
