#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int n, query;

void solve()
{
    cin >> n >> query;
    vector<int> cnt(100005, 0);
    for(int i=0; i<query; i++)
    {
        int l, r;
        cin >> l >> r;
        cnt[l]++, cnt[r + 1]--;
    }

    int s = cnt[0];
    for(int i=1; i<=n; i++)
    {
        s += cnt[i];
        cout << s << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
