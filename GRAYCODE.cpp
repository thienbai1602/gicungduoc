#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int n;
bool cnt[16];
vector<int> tp, edges[16];

bool check(int a, int b)
{
    return (__builtin_popcount(a ^ b) == 1);
}

void dfs(int k)
{
    if (k == (1 << n))
    {
        if (check(0, tp.back()))
        {
            for(int &x : tp) cout << x << " ";
            cout << "\n";
        }
        return;
    }

    for(int v : edges[tp.back()])
    {
        if (!cnt[v] && check(tp.back(), v))
        {
            tp.pb(v); cnt[v] = true;
            dfs(k + 1);
            tp.pop_back(); cnt[v] = false;
        }
    }
}

void solve()
{
    cin >> n;
    for(int i=0; i<(1 << n); i++)
    {
        for(int j=0; j<(1 << n); j++)
        {
            if (i == j) continue;
            if (check(i, j)) edges[i].pb(j);
        }
    }

    memset(cnt, 0, sizeof(cnt));
    cnt[0] = true;
    tp.pb(0);
    dfs(1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
