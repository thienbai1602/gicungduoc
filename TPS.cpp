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
const int mxN = 2e3 + 66;

int n, K;
vector<ll> a;

bool ck(int R)
{
    for(int i=0; i<n; i++)
    {
        int st = a[i], num = 1;
        for(int j=i; j<i+n; j++)
        {
            int diff = (st <= a[j] ? a[j] - st : a[j] + (1000000 - st));
            if (diff > 2 * R)
            {
                st = a[j];
                ++num;
            }
        }
        if (num <= K) return true;
    }
    return false;
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        a.pb(x);
    }
    cin >> K;

    sort(all(a));
    for(int i=0; i<n; i++)
    {
        a.pb(a[i]);
    }

    int l = 0, r = (int)5e5, ans = -1;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if (ck(m))
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
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

