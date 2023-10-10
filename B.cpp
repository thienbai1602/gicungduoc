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

ll numRow, numCol, K;

vector<ii> unique_and_sum(vector<ii> a)
{
    sort(all(a));
    vector<ii> ans;
    for(int i=0; i<sz(a); i++)
    {
        if (!ans.empty() && ans.back().fi == a[i].fi)
        {
            (ans.back().se *= a[i].se) %= MOD;
        } else
        {
            ans.pb(a[i]);
        }
    }
    return move(ans);
}

ll sumAP(ll u1, ll step, ll n)
{
    n %= MOD;
    return (n * ((2 * u1 + (n - 1) * step)) % MOD * ((MOD + 1) >> 1) % MOD) % MOD;
}

ll cell_val(ll row, ll col)
{
    return ((row - 1) * numCol + col) % MOD;
}

void solve()
{
    cin >> numRow >> numCol >> K;
    vector<ii> R, C;
    for(int i=0; i<K; i++)
    {
        char type;
        ll pos, val;
        cin >> type >> pos >> val;
        val %= MOD;
        if (type == 'R') R.pb(mp(pos, val));
         else C.pb(mp(pos, val));
    }

    R = unique_and_sum(R);
    C = unique_and_sum(C);
    ll ans = sumAP(1, 1, numRow * numCol);

    for(int i=0; i<sz(R); i++)
    {
        ll row = R[i].fi;
        ll rowVal = R[i].se;
        ans += (rowVal - 1) * sumAP(cell_val(row, 1), 1, numCol);
        ans %= MOD;
    }

    for(int i=0; i<sz(C); i++)
    {
        ll col = C[i].fi;
        ll colVal = C[i].se;
        ans += (colVal - 1) * sumAP(cell_val(1, col), numCol, numRow);
        ans %= MOD;
    }

    for(int i=0; i<sz(R); i++)
    {
        ll row = R[i].fi;
        ll rowVal = R[i].se;
        for(int j=0; j<sz(C); j++)
        {
            ll col = C[j].fi;
            ll colVal = C[j].se;
            ans += ((colVal - 1) * (rowVal - 1) % MOD) * cell_val(row, col);
            ans %= MOD;
        }
    }
    cout << (ans + MOD) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
