#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e6 + 66;

string S;
ll ret = 0;
int n, K, cnt[mxN];

void solve()
{
    cin >> K >> S;
    n = sz(S);
    if (K != 0)
    {
        int s = 0;
        cnt[0] = 1;
        for(int i=0; i<n; i++)
        {
            s += S[i] - '0';
            if (s >= K) ret += cnt[s - K];
            ++cnt[s];
        }
        cout << ret;
    } else
    {
        int s = 0;
        cnt[0] = 1;
        ll ret = 0;
        for(int i=0; i<n; i++)
        {
            s += S[i] - '0';
            ret += cnt[s]++;
        }
        cout << ret;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("SUBSTR.INP", "r", stdin);
    freopen("SUBSTR.OUT", "w", stdout);
    solve();
    return 0;
}
