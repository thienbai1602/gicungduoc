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

int N;
map<ll, ll> mpref, msuf;
ll a[mxN], pref[mxN], suf[mxN], L[mxN], R[mxN];

void solve()
{
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        cin >> a[i];
    }

    set0(pref);
    mpref[0]++;
    for(int i=1; i<=N; i++)
    {
        pref[i] = pref[i - 1] + a[i];
        L[i] = mpref[pref[i]]++;
    }

    set0(suf);
    msuf[0]++;
    for(int i=N; i>0; i--)
    {
        suf[i] = suf[i + 1] + a[i];
        R[i] = msuf[suf[i]]++;
    }

    ll ans = 0;
    map<ii, int> pos;
    for(int i=1; i<=N; i++)
    {
        int j = pos[mp(pref[i], suf[i])];
        ans += (L[i] - L[j]) * R[i];
        pos[mp(pref[i], suf[i])] = i;
    }
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
