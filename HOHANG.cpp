#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 305;

int tc, n, cnt[mxN];
string A, B;

void solve()
{
    cin >> n >> A >> B;
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<n; i++)
    {
        ++cnt[A[i]];
    }

    for(int i=0; i<n; i++)
    {
        --cnt[B[i]];
    }

    bool check = true;
    for(int i=0; i<305; i++)
    {
        if (cnt[i] != 0) check = false;
    }
    cout << check << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
