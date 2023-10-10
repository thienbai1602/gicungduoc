#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 166;

int tc, n, m;
int deg[mxN];

void solve()
{
    cin >> n >> m;
    memset(deg, 0, sizeof(deg));
    for(int i=0; i<m; i++)
    {
        int u, v, k;
        cin >> u >> v >> k;
        --u, --v;
        deg[u] += k;
        deg[v] += k;
    }

    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        cnt += (deg[i] & 1);
    }

    if (cnt == 0) cout << "euler\n";
     else if (cnt == 2) cout << "nua euler\n";
      else cout << "khong\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
