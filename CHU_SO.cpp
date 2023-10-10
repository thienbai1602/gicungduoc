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

int tc;
ll N, ans;

bool ck(vector<int>& num, ll X)
{
    int digit = 9;
    for(int i=sz(num)-1; i>=0; i--)
    {
        if (num[i] < digit) return false;
        if (num[i] > digit) return true;
        --digit;
    }
    return true;
}

void recur(vector<int> &num, int siz, ll X, int mask, bool tight)
{
    if (siz == 0)
    {
        if (X > N)
        {
            ans = X;
        }
        return;
    }

    if (ans != 0) return;
    int st = tight ? num[sz(num) - siz] : 0;
    for(int digit=st; digit<=9; digit++)
    {
        if ((mask >> digit) & 1) continue;
        recur(num, siz-1, X * 10 + digit, (mask | (1 << digit)), tight && (digit == st));
        if (ans != 0) return;
    }
}

void solve()
{
    cin >> N;
    ll tmp = N;
    vector<int> num;
    while(tmp)
    {
        num.pb(tmp % 10);
        tmp /= 10;
    }

    if (N == 0)
    {
        cout << "1\n";
        return;
    }

    ans = 0;
    if (ck(num, N))
    {
        cout << "10";
        for(int i=1, digit=2; i<sz(num); i++, digit++)
        {
            cout << digit;
        }
        cout << "\n";
        return;
    }
    reverse(all(num));
    recur(num, sz(num), 0, 0, 1);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> tc;
    while(tc--) solve();
    return 0;
}

