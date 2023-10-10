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

int n, Q;
vector<ll> s, diff, pref;

void solve()
{
    cin >> n;
    s.assign(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> s[i];
    }

    sort(all(s));
    diff.assign(n - 1, 0);
    for(int i=0; i<n-1; i++)
    {
        diff[i] = s[i + 1] - s[i];
    }

    sort(all(diff));
    pref.assign(n, 0);
    for(int i=1; i<n; i++)
    {
        pref[i] = pref[i - 1] + diff[i - 1];
    }

    cin >> Q;
    while(Q--)
    {
        ll l, r, w;
        cin >> l >> r;
        w = r - l + 1;
        int idx = lower_bound(all(diff), w) - diff.begin();
        cout << pref[idx] + (n - idx) * w << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
