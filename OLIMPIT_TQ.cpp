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
const int mxN = 1e6 + 66;

int n;

void solve()
{
    cin >> n;
    vector<int> cnt(3, 0);
    for(int i=0; i<n; i++)
    {
        ll T = 0, V = 0, C = 0;
        string S;
        cin >> S;
        for(char &chr : S)
        {
            if (chr == 'T') T++;
             else if (chr == 'V') V++;
              else C++;
        }

        ll mx = max({T, V, C});
        if (mx == T) ++cnt[0];
         else if (mx == V) ++cnt[1];
          else ++cnt[2];
    }

    for(int i=0; i<3; i++)
    {
        cout << cnt[i] << " ";
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
