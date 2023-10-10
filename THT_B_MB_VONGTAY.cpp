#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define mp make_pair
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 40;

int n, m;
map<ii, ll> ms;
ll S, a[mxN], ans = 0;

void meet_in_the_middle(bool flat, int l, int r)
{
    int sz = (r - l);
    for(int mask=0; mask<(1 << sz); mask++)
    {
        ll tot = 0, cnt = 0;
        for(int j=0; j<sz; j++)
        {
            if ((mask >> j) & 1)
            {
                tot += a[j + l];
                cnt++;
            }
        }
        if (flat) ans += ms[mp(S - tot, m - cnt)];
         else ms[mp(tot, cnt)]++;
    }
}

void solve()
{
    cin >> n >> m >> S;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    meet_in_the_middle(0, 0, n / 2);
    meet_in_the_middle(1, n / 2, n);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
