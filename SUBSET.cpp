#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

int n, Q;
ll a[mxN], fen[mxN];

void upd(int id, ll x)
{
    for(; id<=n; id+=(id & -id))
    {
        fen[id] += x;
    }
}

ll get(int id)
{
    ll ans = 0;
    for(; id>0; id-=(id & -id))
    {
        ans += fen[id];
    }
    return ans;
}

ll pw(ll b)
{
    if (b <= 0) return 1;
    if (b == 1) return 2;
    ll t = pw(b / 2);
    t = ((t % MOD) * (t % MOD)) % MOD;
    return (b % 2 == 0 ? t % MOD : (2 * t) % MOD);
}

void solve()
{
    cin >> n >> Q;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        upd(i, !(a[i] & 1));
    }

    while(Q--)
    {
        int type;
        cin >> type;
        if (type == 2)
        {
            int l, r;
            cin >> l >> r;
            ll even = get(r) - get(l - 1);
            ll odd = (r - l + 1) - even;
            cout <<  (ll)(pw(even + max(odd - 1, 0LL)) % MOD - 1 + MOD) % MOD << "\n";
        } else
        {
            ll k, val, nxt = 0;
            cin >> k >> val;
            if ((val & 1) && !(a[k] & 1)) nxt = -1;
             else if (!(val & 1) && (a[k] & 1)) nxt = 1;
            upd(k, nxt);
            a[k] = val;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("SUBSET.INP", "r", stdin);
    //freopen("SUBSET.OUT", "w", stdout);
    solve();
    return 0;
}
