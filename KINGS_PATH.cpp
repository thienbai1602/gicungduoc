#include    <bits/stdc++.h>
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int n;
ii st, ed;
map<ii, bool> sf;

void solve()
{
    cin >> st.fi >> st.se >> ed.fi >> ed.se >> n;
    for(int i=0; i<n; i++)
    {
        int r, x, y;
        cin >> r >> x >> y;
        for(; x<=y; x++)
        {
            sf[mp(r, x)] = true;
        }
    }

    map<ii, int> path;
    path[st] = 1;
    queue<ii> pq;
    pq.push(st);
    while(!pq.empty())
    {
        ii cur = pq.front();
        pq.pop();

        for(int i=0; i<8; i++)
        {
            int ux = cur.fi + dx[i], vx = cur.se + dy[i];
            if (sf[mp(ux, vx)] && path[mp(ux, vx)] == 0)
            {
                path[mp(ux, vx)] = path[cur] + 1;
                pq.push(mp(ux, vx));
            }
        }
    }
    cout << (path[ed] ? path[ed] - 1 : -1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
