#include    <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define ii pair<ll, ll>
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;

int n, K;
vector<ll> lst;
map<ll, ll> pref;

void solve()
{
    cin >> n >> K;
    for(int i=0; i<n; i++)
    {
        ll a, b;
        cin >> a >> b;
        ++pref[a];
        --pref[b + 1];
        lst.pb(a), lst.pb(b + 1);
    }

    sort(all(lst));
    lst.erase(unique(all(lst)), lst.end());

    for(int i=1; i<sz(lst); i++)
    {
        pref[lst[i]] += pref[lst[i - 1]];
    }

    ll ret = 0;
    for(int i=1; i<sz(lst); i++)
    {
        if (pref[lst[i - 1]] == K)
        {
            ret += lst[i] - lst[i - 1];
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("DC.INP", "r", stdin);
    freopen("DC.OUT", "w", stdout);
    solve();
    return 0;
}
