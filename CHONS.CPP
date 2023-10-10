#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int N;
bitset<mxN> can;

void solve()
{
    cin >> N;
    can[0] = 1;
    for(int i=0; i<N; i++)
    {
        int x;
        cin >> x;
        can |= (can << x);
    }
    cout << can.count() - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
