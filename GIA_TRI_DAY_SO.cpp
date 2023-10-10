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
const int mxN = 1e5 + 66;

int n;
ll a[mxN], diff[mxN];
multiset<ll> store, listID;

void solve()
{
    cin >> n;
    ll st = 0;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        diff[i] = a[i] - i;
        st += abs(diff[i]);
        store.insert(diff[i]);
    }

    cout << st << " ";
    ll ans = st;
    for(int i=1; i<n; i++)
    {
        while(!store.empty() && *store.begin() <= i)
        {
            store.erase(store.find(*store.begin()));
        }
        if (store.find(diff[n - i  + 1]) != store.end()) store.erase(store.find(diff[n - i + 1]));

        st += (n - sz(store) - i);
        st -= (abs(diff[n - i + 1]) + (i - 1));
        st += abs(diff[n - i + 1] + (n - i));
        st -= sz(store);

        int number = sz(listID), ct = 0;
        while(!listID.empty() && *listID.begin() < i - 1)
        {
            ++ct;
            listID.erase(listID.find(*listID.begin()));
        }
        listID.insert(diff[n - i + 1] + n - 1);
        st += ct;
        st -= (number - ct);
        ans = max(ans, st);
        //if (i == 4) cout << sz(listID) << " ";
        //if (i == 3) cout << number << " " << ct << "\n";
        cout << st << " ";
    }

    /*for(int i=1; i<=n; i++)
    {
        //cout << diff[i] << " ";
    }*/
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
