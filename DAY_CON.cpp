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
vector<ll> a, lmax, rmax, lmin, rmin;

void left()
{
    stack<int> st;
    lmax.assign(n + 1, 0);
    for(int i=1; i<=n; i++)
    {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        lmax[i] = (st.empty() ? 1 : st.top() + 1);
        st.push(i);
    }

    while(!st.empty()) st.pop();
    lmin.assign(n + 1, 0);
    for(int i=1; i<=n; i++)
    {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        lmin[i] = (st.empty() ? 1 : st.top() + 1);
        st.push(i);
    }
}

void right()
{
    stack<int> st;
    rmax.assign(n + 1, 0);
    for(int i=n; i>=1; i--)
    {
        while(!st.empty() && a[st.top()] < a[i]) st.pop();
        rmax[i] = (st.empty() ? n : st.top() - 1);
        st.push(i);
    }

    while(!st.empty()) st.pop();
    rmin.assign(n + 1, 0);
    for(int i=n; i>=1; i--)
    {
        while(!st.empty() && a[st.top()] > a[i]) st.pop();
        rmin[i] = (st.empty() ? n : st.top() - 1);
        st.push(i);
    }
}

void solve()
{
    cin >> n;
    a.assign(n + 1, 0);
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    left(), right();
    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        ans -= (i - lmin[i] + 1) * (rmin[i] - i + 1) * a[i];
        ans += (i - lmax[i] + 1) * (rmax[i] - i + 1) * a[i];
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
