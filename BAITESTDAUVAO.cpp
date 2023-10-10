#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e3 + 66;

ll n, L;
ll green[mxN], red[mxN], pur[mxN], yellow[mxN];

void solve()
{
    cin >> n >> L;
    for(int i=0; i<n; i++)
    {
        cin >> green[i];
    }

    for(int i=0; i<n; i++)
    {
        cin >> red[i];
    }

    for(int i=0; i<n; i++)
    {
        cin >> pur[i];
    }

    for(int i=0; i<n; i++)
    {
        cin >> yellow[i];
    }

    vector<ll> store;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            store.push_back(pur[i] + yellow[j]);
        }
    }

    sort(store.begin(), store.end());

    ll ret = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int ps1 = upper_bound(store.begin(), store.end(), L - (green[i] + red[j])) - store.begin();
            int ps2 = lower_bound(store.begin(), store.end(), L - (green[i] + red[j])) - store.begin();
            ret += (ps1 - ps2);
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
