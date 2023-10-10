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

const int LOG = 21;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 5e5 + 66;

int n, Q;
int a[mxN], lg[mxN], st[LOG][mxN];

int query(int l, int r)
{
    int k = lg[r - l + 1];
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}

void solve()
{
    cin >> n >> Q;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        st[0][i] = a[i];
    }

    lg[1] = 0;
    for(int i=2; i<=n; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }

    for(int k=1; k<LOG; k++)
    {
        for(int i=0; i+(1 << k)-1<n; i++)
        {
            st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }

    while(Q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r-1) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
