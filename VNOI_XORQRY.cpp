#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define mp make_pair
using namespace std;

const int mxN = 3e5 + 66;

int n, Q;
map<ll, ll> ma;
vector<ii> seg[mxN];
ll a[mxN], fen[mxN], ans[mxN];

void update(int id, ll x)
{
    for(; id<=n; id+=(id & -id))
    {
        fen[id] ^= x;
    }
}

ll get(int id)
{
    ll ans = 0;
    for(; id>0; id-=(id & -id))
    {
        ans ^= fen[id];
    }
    return ans;
}

void solve()
{
    cin >> n >> Q;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<Q; i++)
    {
        int u, v;
        cin >> u >> v;
        seg[v].push_back(mp(u, i));
    }

    //cout << "\n";

    memset(fen, 0, sizeof(fen));
    for(int v=1; v<=n; v++)
    {
        if (ma[a[v - 1]])
        {
            update(ma[a[v - 1]], a[v - 1]);
            update(v, a[v - 1]);
            ma[a[v - 1]] = v;
        } else
        {
            ma[a[v - 1]] = v;
            update(v, a[v - 1]);
        }

        for(auto [u, id] : seg[v])
        {
            ans[id] = get(v) ^ get(u - 1);
            //cout << u << " " << v << " " << id << "\n";
        }
    }

    for(int i=0; i<Q; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
