#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;

void solve()
{
    cin >> N;
    ll sq = (ll)sqrt(N);
    sq -= (sq % 2 == 0);
    for(; sq>0; sq-=2)
    {
        if (N % sq == 0)
        {
            cout << N / sq;
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
