#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int n, K, x[mxN], pref[mxN], nearPos[mxN];
vector<int> index;

bool sf(int X)
{
    for(int &val : index)
    {
        ll cnt = K, cur = val, tot = 0;
        while(cnt--)
        {
            int near = nearPos[cur];
            if (near + X * 2 < (int)1e6) tot += pref[near + X * 2] - pref[near - 1];
             else tot += pref[(near + 2 * X) % (int)1e6] + pref[(int)1e6] - pref[near - 1];
            cur = nearPos[(near + 2 * X + 1) % (int)1e6];
            if (tot >= n) return true;
        }
    }
    return false;
}

int bs(int l, int r)
{
    int ans = -1;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if (sf(m))
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> n;
    set0(x);
    int mi = INT_MAX;
    for(int i=0; i<n; i++)
    {
        int pos;
        cin >> pos;
        ++x[pos];
        index.pb(pos);
        mi = min(mi, pos);
    }
    cin >> K;

    sort(all(index));
    set0(pref);
    for(int i=0; i<=(int)1e6; i++)
    {
        pref[i] = (i == 0 ? x[i] : pref[i - 1] + x[i]);
    }


    for(int pos=(int)1e6-1; pos>=0; pos--)
    {
        if (x[pos]) mi = pos;
        nearPos[pos] = mi;
    }
    cout << bs(0, 1e6);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
