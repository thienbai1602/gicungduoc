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

int N;
vector<ll> money = {1, 2, 5, 10, 20, 50, 100};

void solve()
{
    cin >> N;
    vector<ll> pref(7, 0), x(7);
    for(int i=0; i<7; i++)
    {
        pref[i] = (i == 0 ? money[i] : pref[i - 1] + money[i]);
    }

    for(int i=6; i>=0; i--)
    {
        int l = 0, r = (ll)1e5, ans = 0;
        while(l <= r)
        {
            int m = (l + r) >> 1;
            if (pref[i] * m <= N)
            {
                ans = m;
                l = m + 1;
            } else
            {
                r = m - 1;
            }
        }
        x[i] = ans;
        N -= money[i] * ans;
    }

    for(int i=0; i<7; i++)
    {
        cout << money[i] << " " << x[i] << "\n";
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
