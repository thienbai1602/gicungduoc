#include    <bits/stdc++.h>
#define ll unsigned long long
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

int n;
ll a[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    //sort(a, a + n);
    ll d = a[1] - a[0];
    for(int i=1; i<n; i++)
    {
        if (a[i] - a[i - 1] != d)
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
