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
const int mxN = 2e5 + 66;

int tc, n;
vector<ll> a, pref, suff;

vector<int> left()
{
    stack<int> st;
    vector<int> ans(n);
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        ans[i] = (st.empty() ? -1 : st.top());
        st.push(i);
    }
    return ans;
}

vector<int> right()
{
    stack<int> st;
    vector<int> ans(n);
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        ans[i] = (st.empty() ? n : st.top());
        st.push(i);
    }
    return ans;
}

void build(vector<ll> &seg, vector<ll>& nxt, int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = nxt[l];
        return;
    }

    int m = (l + r) >> 1;
    build(seg, nxt, id << 1, l, m);
    build(seg, nxt, (id << 1) | 1, m + 1, r);
    seg[id] = max(seg[id << 1], seg[(id << 1) | 1]);
}

ll query(vector<ll> &seg, int id, int l, int r, int u, int v)
{
    if (l > v || u > r)
    {
        return -inf;
    }

    if (u <= l && r <= v)
    {
        return seg[id];
    }

    int m = (l + r) >> 1;
    return max(query(seg, id << 1, l, m, u, v), query(seg, (id << 1) | 1, m + 1, r, u, v));
}

void solve()
{
    cin >> n;
    a.assign(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    vector<ll> preS(n, 0), sufS(n, 0);
    for(int i=0; i<n; i++)
    {
        preS[i] = a[i] + (i == 0 ? 0 : preS[i - 1]);
    }

    for(int i=n-1; i>=0; i--)
    {
        sufS[i] = a[i] + (i == n-1 ? 0 : sufS[i + 1]);
    }

    pref.assign(4 * n, -inf);
    suff.assign(4 * n, -inf);
    build(pref, preS, 1, 0, n - 1);
    build(suff, sufS, 1, 0, n - 1);

    vector<int> l = left();
    vector<int> r = right();

    bool flat = true;
    for(int i=0; i<n; i++)
    {
        ll rightMax = query(pref, 1, 0, n - 1, i + 1, r[i] - 1) - preS[i];
        ll leftMax = query(suff, 1, 0, n - 1, l[i] + 1, i - 1) - sufS[i];
        if (max(rightMax, leftMax) > 0)
        {
            flat = false;
            break;
        }
    }
    cout << (flat ? "YES\n" : "NO\n");
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
