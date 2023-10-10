#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int n, K;
ll cnt[10];

void solve()
{
    cin >> n >> K;
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        ++cnt[x % K];
    }

    ll ret = cnt[0];
    if (K == 4)
    {
        for(int i=1; i<3; i++)
        {
            if (i < 2)
            {
                ll tp = min(cnt[i], cnt[K - i]);
                ret += tp;
                cnt[i] -= tp, cnt[K - i] -= tp;
            } else
            {
                ret += cnt[2] / 2;
                cnt[2] %= 2;
            }
        }

        ll tp = min(cnt[1] / 2, cnt[2]);
        cnt[1] -= tp * 2, cnt[2] -= tp;
        ret += tp;

        tp = min(cnt[2], cnt[3] / 2);
        cnt[2] -= tp, cnt[3] -= tp * 2;
        ret += tp;

        tp = min(cnt[1] / 2, cnt[3] / 2);
        cnt[1] -= tp * 2, cnt[3] -= tp * 2;
        ret += tp;

        tp = min({cnt[1], cnt[2] / 2, cnt[3]});
        cnt[1] -= tp, cnt[2] -= tp * 2, cnt[3] -= tp;
        ret += tp + cnt[1] / 4 +  cnt[3] / 4;
    } else
    {
        for(int i=1; i<3; i++)
        {
            ll tp = min(cnt[i], cnt[K - i]);
            ret += tp;
            cnt[i] -= tp, cnt[K - i] -= tp;
        }

        ll tp = min(cnt[1] / 2, cnt[3]);
        cnt[1] -= tp * 2, cnt[3] -= tp;
        ret += tp;

        tp = min(cnt[2] / 2, cnt[1]);
        cnt[1] -= tp, cnt[2] -= 2 * tp;
        ret += tp;

        tp = min(cnt[3] / 2, cnt[4]);
        cnt[3] -= tp * 2, cnt[4] -= tp;
        ret += tp;

        tp = min(cnt[2], cnt[4] / 2);
        cnt[2] -= tp, cnt[4] -= tp * 2;
        ret += tp;

        tp = min(cnt[1] / 3, cnt[2]);
        cnt[2] -= tp, cnt[1] -= tp * 3;
        ret += tp;

        tp = min({cnt[1], cnt[2], cnt[3], cnt[4]});
        for(int i=1; i<5; i++) cnt[i] -= tp;
        ret += tp;

        tp = min(cnt[1] / 2, cnt[4] / 2);
        cnt[1] -= tp * 2, cnt[4] -= tp * 2;
        ret += tp;

        tp = min(cnt[2], cnt[4] / 2);
        cnt[2] -= tp, cnt[4] -= tp * 2;
        ret += tp;

        tp = min(cnt[2] / 3, cnt[4]);
        cnt[2] -= tp * 3, cnt[4] -= tp;
        ret += tp + cnt[1] / 5 + cnt[2] / 5 + cnt[3] / 5 + cnt[4] / 5;
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
