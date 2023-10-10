#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 3e5 + 66;

int n, K;
ll a[mxN];

void solve()
{
    cin >> n >> K;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    ll ret = 0;
    for(int i=0; i<K; i++)
    {
        ret += a[i];
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
