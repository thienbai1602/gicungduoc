#include    <bits/stdc++.h>
#define ll unsigned long long
#define sz(x) (int)x.size()
using namespace std;

const ll INF = 2e18;

string num;
ll N, K, pw[70];

ll sol(ll N, ll K)
{
    if (K <= sz(num)) return (ll)(num[K - 1] - '0');
    if (K <= pw[N] / 2) return sol(N - 1, K);
     else return sol(N - 1, pw[N] - K + 1);
}

void solve()
{
    cin >> num >> N >> K;
    pw[0] = sz(num);
    for(int i=1; i<=N; i++)
    {
        ll nxt = pw[i - 1] * 2;
        pw[i] = min(INF, nxt);
    }

    if (pw[N] < K) cout << -1;
     else cout << sol(N, K);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
