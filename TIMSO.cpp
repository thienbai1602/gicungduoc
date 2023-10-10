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

ll n, sz_M, M;
vector<int> num;

int sl(ll X)
{
    int ans = 0;
    while(X > 0)
    {
        ++ans;
        X /= 10;
    }
    return ans;
}

void sol(vector<int>& num, int N, string cur, ll mask, bool tight)
{
    if (N == 11) return;
    if (N >= sz_M)
    {
        if (N == sz_M && !tight)
        {
            cout << cur;
            exit(0);
        }
    }

    for(int digit=0; digi<=9; digit++)
    {
        if (tight)
        {
            if (digit >=)
        }
    }
}

void solve()
{
    cin >> n >> M;
    num.resize(10, 0);
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        ++num[x];
    }

    sz_M = sl(M);
    sol(num, 0, "", 0, 1);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
