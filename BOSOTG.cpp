#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 5066;

int n;
ll a[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    ll ret = 0;
    for(int i=n-1; i>=0; i--)
    {
        int l = 0, r = i - 1;
        while(l < r)
        {
            if (a[l] + a[r] <= a[i])
            {
                l++;
            } else
            {
                ret += (r - l);
                r--;
            }
        }
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
