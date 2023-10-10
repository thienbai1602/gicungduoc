#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int n, K;
int a[mxN];

void solve()
{
    cin >> n >> K;
    if (K == 0)
    {
        for(int i=1; i<=n; i++) cout << i << " ";
        return;
    }

    if (n % (2 * K) != 0) cout << -1;
     else
     {
         bool check = 0;
         for(int i=1; i<=n; i++)
         {
             a[i] = (!check ? i + K : i - K);
             if (i % K == 0)
             {
                 check = (i / K & 1);
             }
         }

         for(int i=1; i<=n; i++) cout << a[i] << " ";
     }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
