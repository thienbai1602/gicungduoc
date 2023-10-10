#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int timer;
ll tot_time[366];

void solve()
{
    memset(tot_time, 0, sizeof(tot_time));

    ll ans = 0, sz = 0;
    while(cin >> timer)
    {
        if (timer == -1) break;
        char task;
        string f;
        cin >> task >> f;
        if (f.front() == 'r')
        {
            ++sz;
            ans += timer + tot_time[task];
        } else
        {
            tot_time[task] += 20;
        }
    }
    cout << sz << " " << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
