#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int n, K;
ll ct = 0, s = 0;

void solve()
{
    cin >> n >> K;
    vector<ll> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    map<ll, ll> cnt;
    for(int i=0; i<n; i++)
    {
        if (++cnt[a[i]] == K)
        {
            ct++;
            s += a[i];
        }
    }
    cout << ct << " " << s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
