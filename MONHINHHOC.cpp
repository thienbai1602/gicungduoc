#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 66;

ll n, cnt[N], pref[N];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    pref[0] = 0;
    for(int i=1; i<N; i++)
    {
        pref[i] = pref[i - 1] + cnt[i];
    }

    ll ret = 0;
    for(int i=1; i<N; i++)
    {
        if (cnt[i] > 1)
        {
            ll tp = (cnt[i] - 1) * cnt[i] / 2;
            //cout << i << " " << pref[i * 2 - 1] << "\n";
            ret += tp * (pref[2 * i - 1] - cnt[i]);
            ret += (cnt[i] - 1) * (cnt[i] - 2) * cnt[i] / 6;
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
