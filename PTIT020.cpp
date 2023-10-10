#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll K;
string s;

void solve()
{
    cin >> K >> s;
    ll L = (int)s.size();
    while(K > L)
    {
        ll tp = L;
        while(tp * 2 < K)
        {
            tp *= 2;
        }
        K = (K - tp - 1);
        if (K == 0) K = tp;
    }
    cout << s[K - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
