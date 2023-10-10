#include    <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
using namespace std;

const int mxN = 1e6 + 66;

int cnt[mxN];
ll N, P, R, pl[2];

void bfs()
{
    queue<ll> que;
    memset(cnt, -1, sizeof(cnt));
    for(int mask=1; mask<4; mask++)
    {
        ll tp = N;
        for(int j=0; j<2; j++)
        {
            if ((1 << j) & mask)
            {
                tp += pl[j];
            }
        }
        que.push(tp % P);
        cnt[tp % P] = 1;
        que.push(tp % P);
    }

    while(!que.empty())
    {
        ll nxt = que.front();
        que.pop();

        for(int mask=1; mask<4; mask++)
        {
            ll tp = nxt;
            for(int j=0; j<2; j++)
            {
                if ((1 << j) & mask)
                {
                    tp += pl[j];
                }
            }
            tp %= P;

            if (cnt[tp] == -1)
            {
                cnt[tp] = cnt[nxt] + 1;
                que.push(tp);
            }
        }
    }
}

void solve()
{
    cin >> N >> P >> pl[0] >> pl[1] >> R;
    bfs();
    cout << cnt[R];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
