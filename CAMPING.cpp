#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 5e5 + 66;

int n, X, a[mxN];

void solve()
{
    cin >> n >> X;
    vector<ll> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    a.pb(X);

    sort(all(a));
    a.erase(unique(all(a)), a.end());
    for(int i=0; i<sz(a); i++)
    {
        if (a[i] == X)
        {
            cout << i + 1;
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
