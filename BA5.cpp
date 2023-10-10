#include    <bits/stdc++.h>
#define ll unsigned long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

ll N, K;

int digit(int x)
{
    int cnt = 0;
    while(x > 0)
    {
        cnt++;
        x /= 10;
    }
    return cnt;
}

void solve()
{
    cin >> N >> K;
    ll sz = 1;
    for(int i=2; i<=N; i++)
    {
        sz = sz * 2 + digit(i);
        if (sz > K) break;
    }

    if (sz < K)
    {
        cout << -1 << "\n";
        return;
    }

    while(K > 1)
    {
        int ct; sz = 1;
        for(ct=2; ct<=N; ct++)
        {
            sz = sz * 2 + digit(ct);
            if (sz > K) break;
        }

        if (K == sz)
        {
            cout << 1;
            return;
        }

        //cout << ct << " " << sz << " " << K << "\n";

        if (ct < N || sz / 2 + 1 > K)
        {
            if (K <= digit(N)) break;
            K -= digit(N), N--;
        } else
        {
            K = K - (sz / 2 + 1);
            if (K == 0) K = sz / 2;
            N--;
        }
        //cout << K << "\n";
    }

    //cout << N << "\n";

    int ret = 0, tp = digit(N) - K + 1;
    for(int i=0; i<tp; i++)
    {
        ret = N % 10;
        N /= 10;
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
