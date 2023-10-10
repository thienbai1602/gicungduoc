#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;

void solve()
{
    cin >> N;
    cout << (ll)(N + (N / 10) * 2 - (N / 15) - (N / 30) * 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
