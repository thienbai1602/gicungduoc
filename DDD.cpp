#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6 + 55;

int n;
ll a[mxN], T;

void solve()
{
    cin >> n >> T;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll ret = 0, S = 0;
    int l = 0, r = -1;
    while(r < n - 1)
    {
        while(S <= T && r < n - 1)
        {
            S += a[++r];
            if (S <= T) ret += (r - l + 1);
        }

        //cout << l << " " << r << " " << ret << " " << S << "\n";

        if (r == n - 1 && S <= T) break;

        while(l <= r && S > T)
        {
            S -= a[l++];
        }
        ret += (r - l + 1);
        //cout << l << " " << r << " " << ret << " " << S << "\n";
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("DDC.INP", "r", stdin);
    freopen("DDC.OUT", "w", stdout);
    solve();
    return 0;
}
