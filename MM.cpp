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

string S;

void solve()
{
    cin >> S;
    int num = 0;
    vector<int> ans;
    for(char &chr : S)
    {
        if (chr >= '0' && chr <= '9')
        {
            num = num * 10 + (int)(chr - '0');
        } else
        {
            if (num > 0) ans.pb(num);
            num = 0;
        }
    }

    if (num > 0) ans.pb(num);
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    cout << sz(ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
