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
ii res;
bool flat = false;
vector<ii> eq;
vector<int> store;
vector<char> dau = {'+', '-', 'X'};

ii mul(ii a, ii b)
{
    return mp(a.fi * b.fi, a.se * b.se);
}

void pluss(ii &a, const ii b)
{
    int g = (a.se * b.se) / __gcd(a.se, b.se);
    int f = a.fi * (g / a.se);
    int h = b.fi * (g / b.se);
    a = mp(f + h, g);
}

void minuss(ii &a, const ii b)
{
    int g = (a.se * b.se) / __gcd(a.se, b.se);
    int f = a.fi * (g / a.se);
    int h = b.fi * (g / b.se);
    a = mp(f - h, g);
}

void rut_gon(ii &a)
{
    int g = __gcd(a.fi, a.se);
    a = mp(a.fi / g, a.se / g);
}

bool check(vector<int> &store)
{
    vector<int> cur;
    vector<ii> nxt = {eq[0]};
    for(int i=0; i<n-1; i++)
    {
        if (store[i] != 2)
        {
            cur.pb(store[i]);
            nxt.pb(eq[i + 1]);
        } else
        {
            ii tp = nxt.back();
            nxt.pop_back();
            nxt.pb(mul(tp, eq[i + 1]));
        }
    }

    ii ans = eq[0];
    for(int i=0; i<sz(cur); i++)
    {
        if (cur[i] == 0)
        {
            pluss(ans, nxt[i + 1]);
        } else
        {
            minuss(ans, nxt[i + 1]);
        }
    }
    rut_gon(ans);
    return (ans == res);
}

void backTrack(int l, int r)
{
    if (flat) return;
    if (l > r)
    {
        if (check(store))
        {
            flat = true;
            for(int i=0; i<n-1; i++)
            {
                cout << dau[store[i]];
            }
            return;
        }
        return;
    }

    for(int j=0; j<3; j++)
    {
        store[l] = j;
        backTrack(l + 1, r);
    }
}

ii read(string s)
{
    int signT = 1, signM = 1;
    ll t = 0, m = 0;
    bool ok = true;
    for(char &c : s)
    {
        if (c == '/')
        {
            ok = false;
            continue;
        }

        if (ok)
        {
            if (c == '-') signT = -1;
             else t = t*10 + (int)(c - '0');
        } else
        {
            if (c == '-') signM = -1;
             else m = m * 10 + (int)(c - '0');
        }
    }
    return mp(signT * t, signM * m);
}

void solve()
{
    cin >> n;
    cin.ignore();
    eq.assign(n, mp(0, 0));
    for(int i=0; i<n; i++)
    {
        string c;
        cin >> c;
        eq[i] = read(c);
    }

    string c;
    cin >> c;
    store.assign(n-1, -1);
    res = read(c);
    rut_gon(res);
    backTrack(0, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("phanso1236.inp", "r", stdin);
    freopen("phanso1236.out", "w", stdout);
    solve();
    return 0;
}
