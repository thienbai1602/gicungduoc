#include    <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

const int mxN = 505;
const ll mod = 1e9 + 7;
const ll inv = 500000004;

int query, N;
string _T, _Lim;
vector<int> T, Lim;
ll sum[mxN][mxN][3][3], ct[mxN][mxN][3][3], pw[mxN];

vector<int> trade(string& S)
{
    vector<int> num;
    for(char c : S) num.push_back(c - '0');
    return num;
}

int fix_left(int ok , ll a, ll b)
{
    if (ok == 1) return 1;
    if (ok == 0)
    {
        if (a < b) return 1;
        if (a == b) return 0;
    }
    return 2;
}

int fix_right(int ok, ll a, ll b)
{
    if (a < b) return 1;
    if (a == b) return ok;
    return 2;
}

pair<ll, ll> sol(int left, int right, int okL, int okR)
{
    ll& s = sum[left][right][okL][okR];
    ll& cnt = ct[left][right][okL][okR];
    if (s != -1) return {s, cnt};

    if (left + right == N)
    {
        if (okL == 1 || (!okL && okR < 2))
        {
            return {0, 1};
        } else
        {
            return {0, 0};
        }
    }

    s = 0, cnt = 0;
    int digit = T[N - left - right - 1];
    {
        int pos = N - left - 1;
        int newokL = fix_left(okL, digit, Lim[left]);
        if (newokL != 2)
        {
            pair<ll, ll> nxt = sol(left + 1, right, newokL, okR);
            cnt += nxt.se;
            ll bonus = nxt.fi % mod;
            bonus += 1LL * digit * pw[pos] % mod * nxt.se % mod;
            s = (s + bonus) % mod;
        }
    }

    {
        int pos = right;
        int newokR = fix_right(okR, digit, Lim[N - right - 1]);
        pair<ll, ll> nxt = sol(left, right + 1, okL, newokR);
        cnt = (cnt + nxt.se) % mod;
        ll bonus = nxt.fi;
        bonus = (bonus + 1LL * digit * pw[pos] % mod * nxt.se % mod) % mod;
        s = (s + bonus) % mod;
    }
    sum[left][right][okL][okR] = s, ct[left][right][okL][okR] = cnt;
    return {s, cnt};
}

ll pwr(ll a, ll b)
{
    if (b == 0) return 1;
    if (b == 1) return a % mod;
    ll t = pwr(a, b / 2);
    t = ((t % mod) * (t % mod)) % mod;
    if (b % 2 == 0) return t % mod;
     else return ((a % mod) * (t % mod)) % mod;
}

void solve()
{
    cin >> _T >> _Lim;
    T = trade(_T), Lim = trade(_Lim);
    memset(sum, -1, sizeof(sum));
    memset(ct, -1, sizeof(ct));

    N = (int)T.size();
    if((int)T.size() < (int)Lim.size())
    {
        Lim = vector<int>(N, 9);
    }

    while ((int)T.size() > (int)Lim.size())
    {
        Lim.insert(Lim.begin(), 0);
    }
    cout << sol(0, 0, 0, 0).fi * pwr(2, mod - 2) % mod <<  "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pw[0] = 1;
    for(int i=1; i<mxN; i++)
    {
        pw[i] = (pw[i - 1] * 10) % mod;
    }

    cin >> query;
    while(query--) solve();
    return 0;
}
