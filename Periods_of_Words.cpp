#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int K, pi[mxN];
string A;

void solve()
{
    cin >> K >> A;
    pi[0] = 0;
    for(int i=1, j=0; i<K; i++)
    {
        while(j > 0 && A[i] != A[j])
        {
            j = pi[j - 1];
        }
        j += (A[i] == A[j]);
        pi[i] = j;
    }

    ll ans = 0;
    for(int i=1; i<K; i++)
    {
        if (!pi[i]) continue;
        if (pi[pi[i] - 1] != 0) pi[i] = pi[pi[i] - 1];
        ans += (i + 1 - pi[i]);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}

