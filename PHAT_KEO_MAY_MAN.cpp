#include    <bits/stdc++.h>
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 2e5 + 66;

int n, m;
ll pref[mxN];

void solve()
{
    cin >> n >> m;
    vector<ii> candy(n);
    vector<ll> listID;
    for(int i=0; i<n; i++)
    {
        cin >> candy[i].fi >> candy[i].se;
        listID.pb(candy[i].se);
    }

    listID.pb(-1);
    sort(all(listID));
    sort(all(candy), [&](ii &a, ii &b) {return a.se < b.se;});
    for(int i=0, j=0; i<sz(listID); i++)
    {
        while(j < n && candy[j].se == listID[i]) pref[i] += candy[j++].fi;
    }

    for(int i=1; i<sz(listID); i++)
    {
        pref[i] += pref[i - 1];
    }

    /*for(int i=0; i<sz(listID); i++)
    {
        cout << listID[i] << (i < sz(listID) - 1 ? " " : "\n");
    }

    for(int i=0; i<sz(listID); i++)
    {
        cout << pref[i] << (i < sz(listID) - 1 ? " " : "\n");
    }*/

    for(int i=0; i<m; i++)
    {
        ll l, r;
        cin >> l >> r;
        int posL = lower_bound(all(listID), l) - listID.begin() - 1;
        int posR = upper_bound(all(listID), r) - listID.begin() - 1;
        cout << pref[posR] - pref[posL] << " ";
        //cout << posL << " " << posR << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
