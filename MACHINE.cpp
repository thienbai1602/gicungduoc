#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e4 + 66;

struct machine
{
    ll a, b, c, idx;

    bool operator < (machine v)
    {
        return ((a < v.a) || (a == v.a && b < v.b));
    }
};

int n;
ll dp[mxN], pref[mxN];
machine robotic[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> robotic[i].a >> robotic[i].b >> robotic[i].c;
        robotic[i].idx = i + 1;
    }

    sort(robotic, robotic + n);

    for(int i=0; i<n; i++)
    {
        int f = 0;
        ll val = 0;
        for(int j=i-1; j>=0; j--)
        {
            if (robotic[i].a >= robotic[j].b && val < dp[j + 1])
            {
                val = dp[j + 1];
                f = j + 1;
            }
        }
        dp[i + 1] = val + robotic[i].c;
        pref[i + 1] = f;
    }

    ll ret = 0;
    int id = 0;
    for(int i=1; i<=n; i++)
    {
        if (dp[id] < dp[i])
        {
            id = i;
            ret = max(ret, dp[i]);
        }
    }

    vector<int> res;
    while(id > 0)
    {
        res.push_back(robotic[id - 1].idx);
        id = pref[id];
    }

    cout << ret << "\n";
    for(int i=sz(res)-1; i>=0; i--)
    {
        cout << res[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("MACHINE.INP", "r", stdin);
    freopen("MACHINE.OUT", "w", stdout);
    solve();
    return 0;
}
