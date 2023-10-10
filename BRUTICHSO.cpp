#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

ll N, mx = 0, pw[15];

void recur(vector<int>& num, int N, ll T, bool tight)
{
    if (N == 0)
    {
        mx = max(mx, T);
        return;
    }

    if (T * pw[N] <= mx) return;

    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        recur(num, N - 1, max(1LL * 1, T * digit), tight && (digit == limit));
    }
}

ll sol(ll X)
{
    vector<int> num;
    while(X > 0)
    {
        num.push_back(X % 10);
        X /= 10;
    }
    reverse(num.begin(), num.end());
    recur(num, sz(num), 1, 1);
    return mx;
}

void solve()
{
    cin >> N;
    pw[0] = 1;
    for(int i=1; i<=10; i++)
    {
        pw[i] = pw[i - 1] * 9;
    }
    cout << sol(N);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
