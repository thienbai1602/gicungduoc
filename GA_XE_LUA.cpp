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
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

int n, a[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    stack<int> st;
    int id = 1, ans = 0;
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && st.top() == id)
        {
            ++id;
            ++ans;
            st.pop();
        }

        if (a[i] == id)
        {
            ++id;
            ++ans;
        } else
        {
            st.push(a[i]);
            ++ans;
        }
    }
    while(!st.empty() && id == st.top())
    {
        ++id;
        ++ans;
        st.pop();
    }
    cout << (id == n + 1 ? ans : 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
