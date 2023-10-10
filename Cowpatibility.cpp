#include    <bits/stdc++.h>
#define ll long long
#define B bitset<50001>
#define pb push_back
#define sz(x) (int)x.size()
using namespace std;

const int HAFT = 25001;
const int mxN = 1e6 + 66;

int n;
B adj[HAFT];
vector<int> flavor[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<5; j++)
        {
            int x;
            cin >> x;
            flavor[x].pb(i);
        }
    }

    ll ans = 0;
    for(int i=1; i<=1e6; i++)
    {
        if (sz(flavor[i]) > 0)
        {
            B bit;
            for(int x : flavor[i])
            {
                bit[x] = 1;
            }

            for(int x : flavor[i])
            {
                if (x < HAFT)
                {
                    adj[x] |= bit;
                }
            }
        }
    }

    for(int i=0; i<HAFT; i++)
    {
        ans += adj[i].count();
        adj[i].reset();
    }

    for(int i=1; i<=1e6; i++)
    {
        if (sz(flavor[i]) > 0)
        {
            B bit;
            for(int x : flavor[i])
            {
                bit[x] = 1;
            }

            for(int x : flavor[i])
            {
                if (x >= HAFT)
                {
                    adj[x - HAFT] |= bit;
                }
            }
        }
    }

    for(int i=0; i<HAFT; i++)
    {
        ans += adj[i].count();
    }
    cout << ((ll)n * n - ans) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
    solve();
    return 0;
}

