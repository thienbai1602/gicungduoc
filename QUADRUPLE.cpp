#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 4066;

int n, a[mxN];
map<int, ll> ma;

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            ++ma[a[i] - a[j]];
        }
    }

    ll ret = 0;
    for(int j=0; j<n; j++)
    {
        for(int i=j+1; i<n; i++)
        {
            --ma[a[j] - a[i]];
        }

        for(int i=0; i<j; i++)
        {
            if (ma[a[i] - a[j]])
            {
                ret += ma[a[i] - a[j]];
            }
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("QUADRUPLE.INP", "r", stdin);
    freopen("QUADRUPLE.OUT", "w", stdout);
    solve();
    return 0;
}
