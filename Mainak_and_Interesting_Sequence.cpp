#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int tc, n;
ll M;

void solve()
{
    cin >> n >> M;
    if (n > M || (n % 2 == 0) && (M % 2 == 1))
    {
        cout << "No\n";
    } else
    {
        cout << "Yes\n";
        if (n % 2 == 1)
        {
            for(int i=0; i<n-1; i++)
            {
                cout << "1 ";
            }
            cout << M - n + 1 << "\n";
        } else
        {
            for(int i=0; i<n-2; i++)
            {
                cout << "1 ";
            }
            cout << (M - n + 2) / 2 << " " << (M - n + 2) / 2 << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
