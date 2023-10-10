#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 1e5 + 66;

int n, m, K, ct[mxN];
vector<int> cnt;

void solve()
{
    cin >> n >> m >> K;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int x;
            cin >> x;
            ++ct[x];
        }
    }

    for(int i=0; i<=(ll)1e5; i++)
    {
        cnt.pb(ct[i]);
    }

    sort(all(cnt), greater<int>());

    ll ans = 0;
    for(int i=0; i<K; i++)
    {
        ans += cnt[i];
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
