#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int n;
bool isPrime[40], cnt[20], flat = false;
vector<int> ret, tp, p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

void dfs(int k)
{
    if (flat) return;
    if (k == 2 * n + 1)
    {
        if (isPrime[tp.back() + 1])
        {
            flat = true;
            for(int &x : tp) ret.pb(x);
        }
        return;
    }

    for(int j=2; j<=2*n; j++)
    {
        if (isPrime[tp.back() + j] && !cnt[j])
        {
            tp.pb(j); cnt[j] = true;
            dfs(k + 1);
            tp.pop_back(); cnt[j] = false;
        }
    }
}

void solve()
{
    cin >> n;
    memset(cnt, false, sizeof(cnt));
    memset(isPrime, false, sizeof(isPrime));
    clock_t reg;
    reg = clock();
    for(int &x : p) isPrime[x] = true;
    tp.pb(1); cnt[1] = true;
    dfs(2);
    for(int &x : ret) cout << x << " ";
    //reg = clock() - reg;
    //cout << "\n" <<  reg / (float)1000 << " ms";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
