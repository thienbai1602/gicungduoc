#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int tc;
ll N;

void solve()
{
    cin >> N;
    cout << N * (N - 1) / 2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
