#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int tc;
ll N, K;

void solve()
{
    cin >> N >> K;
    bool check = (K % (N - 1));
    ll seg = (K / (N - 1) + check);
    cout << (seg - 1) * N + (!check ? N - 1 : K % (N - 1)) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
