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
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 3e4 + 66;

int tc, n;
stack<int> st;
ll a[mxN], l[mxN], r[mxN];

void left()
{
    set0(l);
    while(!st.empty()) st.pop();
    for(int i=1; i<=n; i++)
    {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        l[i] = (st.empty() ? 1 : st.top() + 1);
        st.push(i);
    }
}

void right()
{
    set0(r);
    while(!st.empty()) st.pop();
    for(int i=n; i>0; i--)
    {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        r[i] = (st.empty() ? n : st.top() - 1);
        st.push(i);
    }
}

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    left(), right();

    ll ans = -inf, st = -1, ed = -1;
    for(int i=1; i<=n; i++)
    {
        if (ans < a[i] * (r[i] - l[i] + 1))
        {
            ans = a[i] * (r[i] - l[i] + 1);
            st = l[i], ed = r[i];
        }
    }
    cout << ans << " " << st << " " << ed << "\n";
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
