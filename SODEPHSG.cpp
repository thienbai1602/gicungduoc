#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 25;

ll n, M;
vector<ll> a;
map<ll, ll> ma;

void solve()
{
    cin >> n >> M;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    ll ret = 0;
    for(int i=0; i<(1 << sz(a)); i++)
    {
        ll nxt = 1, ct = 0;
        for(int j=0; j<sz(a); j++)
        {
            if (i & (1 << j) && nxt <= M / a[j])
            {
                nxt *= a[j];
                ++ct;
            }
        }

        if (ma[nxt] || !ct) continue;
        ma[nxt]++;
        ret += (ct & 1 ? M / nxt : -M / nxt);
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
