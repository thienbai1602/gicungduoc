#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

int n;

void solve()
{
    cin >> n;
    queue<int> st;
    for(int i=1; i<=n; i++)
    {
        st.push(i);
    }

    while(sz(st) > 1)
    {
        int tp = st.front();
        st.pop();
        cout << st.front() << " ";
        st.pop();
        st.push(tp);
    }
    cout << st.front();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
