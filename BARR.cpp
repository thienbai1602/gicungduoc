#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int n;

void solve()
{
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int l = -1; ll ret = 0;
    vector<int> cnt(1000001, 0);
    for(int r=0; r<n; r++)
    {
        if (++cnt[a[r]] > 2)
        {
            while(cnt[a[r]] != 2) --cnt[a[++l]];
        }
        ret += (r - l);
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
