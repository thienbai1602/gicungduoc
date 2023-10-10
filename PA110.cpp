/*#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e3 + 55;

int n;
ll a[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    unordered_map<ll, ll> cnt;
    for(int k=0; k<n-1; k++)
    {
        for(int l=k+1; l<n; l++)
        {
            ans += cnt[a[k] + a[l]];
        }

        for(int i=0; i<k; i++)
        {
            ++cnt[a[i] + a[k]];
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CINDEX.INP", "r", stdin);
    freopen("CINDEX.OUT", "w", stdout);
    solve();
    return 0;
}*/
#include    <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

const int mxN = 1e3 + 55;

int n, sz = 0, ib = 0, ia = 0;
ll a[mxN];
pair<ll, ll> arr[mxN * mxN];

ll cnt(ll X, int pos)
{
    ll ret = 0;
    int l = 0, r = sz - 1, ans = -1;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if (arr[m].fi >= X)
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
    }

    for(; ans<sz; ans++)
    {
        if (arr[ans].se >= pos) break;
        ret++;
    }
    return ret;
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            arr[sz++] = {a[i] + a[j], j};
        }
    }
    sort(arr, arr + sz);

    ll ans = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            ans += cnt(a[i] + a[j], i);
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CINDEX.INP", "r", stdin);
    freopen("CINDEX.OUT", "w", stdout);
    solve();
    return 0;
}
