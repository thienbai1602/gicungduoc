#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mxN = 1e5 + 66;

ll n, A, G, a[mxN];

void solve()
{
    cin >> n >> A >> G;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    multiset<ii> mst;
    for(int i=0; i<n; i++)
    {
        mst.insert(mp(a[i], i + 1));
    }

    ll nxt = A;
    vector<int> ret;
    while(nxt <= G && !mst.empty())
    {
        if ((*mst.begin()).fi >= nxt) break;
        ii ps = *(--mst.lower_bound(mp(nxt, 0)));
        mst.erase(mst.find(ps));
        nxt += ps.fi;
        ret.push_back(ps.se);
    }

    if (nxt <= G) cout << -1;
     else
     {
         cout << (int)ret.size() << "\n";
         for(int& x : ret) cout << x << " ";
     }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
