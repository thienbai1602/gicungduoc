#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

int N;
ii points[mxN][4], rec[mxN][4], turn[mxN];

void solve()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin >> points[i][j].fi >> points[i][j].se;
        }
    }

    for(int i=0; i<N; i++)
    {
        int turn = (points[i][2].fi - points[i][1].fi) / 2;
        bool odd = ((points[i][2].fi - points[i][1].fi) % 2 != 0);
        if (!odd)
        {
            ll x = points[i][0].fi - turn; // duong thang trai
            ll y = points[i][0].se + turn; // duong ngang duoi
            ll z = y + (points[i][1].se - points[i][0].se); // duong ngang tren
            ll t = x + (points[i][3].fi - points[i][0].fi); // duong thang phai
            rec[i][0] = mp(x, y), rec[i][1] = mp(x, z), rec[i][2] = mp(t, z), rec[i][3] = mp(t, y);
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << rec[i][j].fi << " " <<  rec[i][j].se << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}

