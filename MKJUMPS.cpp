#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mxN = 11;
const int u[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int v[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int n;
int ans = 0, mx = 1;
bool table[mxN][mxN];

bool sf(int x, int y)
{

    return (x > 0 && y > 0 && x <= 10 && y <= 10);
}

void dfs(int x, int y, int deep)
{
    for(int i=0; i<8; i++)
    {
        int ux = u[i] + x, vx = v[i] + y;
        if (sf(ux, vx) && table[ux][vx])
        {
            table[ux][vx] = false;
            if (mx < deep + 1) mx = deep + 1;
            dfs(ux, vx, deep + 1);
            table[ux][vx] = true;
        }
    }
}

void solve()
{
    cin >> n;
    ii st = mp(-1, -1);
    memset(table, false, sizeof(table));
    for(int i=0; i<n; i++)
    {
        int id, sz;
        cin >> id >> sz;
        if (st == mp(-1LL, -1LL))
        {
            st = mp(1, id + 1);
        }

        for(int j=id+1; j<=id+sz; j++)
        {
            ans++;
            table[i + 1][j] = true;
        }
    }
    table[st.fi][st.se] = false;
    dfs(st.fi, st.se, 1);
    cout << ans - mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
