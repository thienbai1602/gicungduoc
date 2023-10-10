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

int N, M;
int fen[mxN], p[mxN], b[mxN];

void upd(int id, int x)
{
    for(; id<=N; id+=(id & -id))
    {
        fen[id] = max(fen[id], x);
    }
}

int get(int id)
{
    int ans = 0;
    for(; id>0; id-=(id & -id))
    {
        ans = max(ans, fen[id]);
    }
    return ans;
}

void solve()
{
    cin >> N >> M;
    for(int i=1; i<=N; i++)
    {
        int x;
        cin >> x;
        p[x] = i;
    }

    for(int i=1; i<=M; i++)
    {
        cin >> b[i];
    }

    set0(fen);
    for(int i=1; i<=M; i++)
    {
        if (b[i] > N) continue;
        int pos = p[b[i]];
        upd(pos, get(pos - 1) + 1);
    }
    cout << get(N);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
