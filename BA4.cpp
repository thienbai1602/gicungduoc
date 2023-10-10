#include    <bits/stdc++.h>
#define ll unsigned long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 2e5 + 66;

int n;
ll X, a[mxN];
map<ll, ll> ma;

void solve()
{
    cin >> n >> X;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll ret = 0;
    for(int i=0; i<n; i++)
    {
        if (X <= a[i]) continue;
        ret += ma[X - a[i]];
        ma[a[i]]++;
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
