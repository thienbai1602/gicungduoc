#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e5 + 66;

int n;
ll h[mxN];
string S;
stack<int> st;

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> h[i];
    }
    cin >> S;

    vector<ll> l(n), r(n);
    for(int i=n-1; i>=0; i--)
    {
        l[i] = sz(st);
        while(!st.empty() && h[st.top()] < h[i]) st.pop();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i=0; i<n; i++)
    {
        r[i] = sz(st);
        while(!st.empty() && h[st.top()] < h[i]) st.pop();
        st.push(i);
    }

    for(int i=0; i<sz(S); i++)
    {
        cout << (S[i] == 'E' ? l[i] : r[i]) << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CAMERA.INP", "r", stdin);
    freopen("CAMERA.OUT", "w", stdout);
    solve();
    return 0;
}
