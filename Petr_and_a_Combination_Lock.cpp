#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 20;

int n, a[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<(1<<n); i++)
    {
        int degree = 0;
        for(int j=0; j<n; j++)
        {
            degree += (i & (1 << j) ? -a[j] : a[j]);
        }

        if (degree % 360 == 0)
        {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
