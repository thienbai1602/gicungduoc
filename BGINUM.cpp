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

vector<int> num;
string S;
int K;

void solve()
{
    cin >> S >> K;
    for(int i=0; i<sz(S); i++)
    {
        if (S[i] >= '0' && S[i] <= '9') num.pb(S[i] - '0');
    }

    vector<int> ans;
    for(int i=0; i<sz(num); i++)
    {
        while (!ans.empty() && sz(ans) + (sz(num) - i - 1) >= K && ans.back() < num[i]) ans.pop_back();
        if (ans.empty() || sz(ans) < K) ans.pb(num[i]);
    }
    for(int x : ans) cout << x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("BIGNUM.INP", "r", stdin);
    freopen("BIGNUM.OUT", "w", stdout);
    solve();
    return 0;
}
