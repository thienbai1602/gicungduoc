#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e6 + 66;

int n;
ll year[mxN];

void solve()
{
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++)
    {
        string S;
        getline(cin, S);
        for(int j=sz(S)-4; j<sz(S); j++)
        {
            year[i] = year[i] * 10 + (S[j] - '0');
        }
    }

    sort(year, year + n);

    ll ans = -1, st = -1;
    for(int i=0; i<n-1; i++)
    {
        if (year[i + 1] - year[i] > ans)
        {
            ans = year[i + 1] - year[i];
            st = i;
        }
    }
    cout << ans - 1 << "\n" << year[st] + 1 << " " << year[st + 1] - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
