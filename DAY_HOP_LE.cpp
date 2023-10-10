#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int tc;
char sf[366];

void solve()
{
    stack<char> st;
    string S;
    cin >> S;

    for(int i=0; i<(int)S.size(); i++)
    {
        if (S[i] == '[' || S[i] == '{' || S[i] == '(')
        {
            st.push(S[i]);
            continue;
        }

        if (st.empty())
        {
            cout << 0 << "\n";
            return;
        }

        char c = st.top(); st.pop();
        if (sf[S[i]] != c)
        {
            cout << 0 << "\n";
            return;
        }
    }
    cout << (st.empty() ? 1 : 0) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc; cin.ignore();
    sf[']'] = '[', sf['}'] = '{', sf[')'] = '(';
    while(tc--) solve();
    return 0;
}
