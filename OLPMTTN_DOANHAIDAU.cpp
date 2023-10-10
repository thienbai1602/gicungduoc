#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;

const int mxN = 5e5 + 66;

int n;
int fen[mxN];

void update(int id)
{
    for(; id<=n; id+=(id & -id))
    {
        fen[id]++;
    }
}

int get(int id)
{
    ll res = 0;
    for(; id>0; id-=(id & -id))
    {
        res += fen[id];
    }
    return res;
}

ll sol(vector<int>& a)
{
    stack<int> st;
    vector<ii> l(n + 1);
    memset(fen, 0, sizeof(fen));
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && a[st.top()] > a[i]) st.pop();
        l[i + 1].fi = (st.empty() ? 1 : st.top() + 2);
        l[i + 1].se = i + 1;
        st.push(i);
    }

    while(!st.empty()) st.pop();

    vector<ii> r(n + 1);
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && a[st.top()] < a[i]) st.pop();
        r[i + 1].fi = i + 1;
        r[i + 1].se = (st.empty() ? n : st.top());
        st.push(i);
    }

    sort(l.begin(), l.end());

    ll ans = 0;
    for(int i=0, pos=0; i<n; i++)
    {
        ii nxt = r[i + 1];
        while(pos < n && l[pos + 1].fi <= nxt.fi)
        {
            update(l[++pos].se);
        }
        ans += get(nxt.se) - get(nxt.fi - 1);
    }
    return ans;
}

void solve()
{
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll ret = 0;
    ret += sol(a);
    reverse(a.begin(), a.end());
    ret += sol(a);
    cout << ret - n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
