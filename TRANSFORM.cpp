#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int Q;
ll A, B;
bool flat;

void dfs(ll A, ll B)
{
    if (A > B || flat) return;
    if (A == B)
    {
        flat = true;
        return;
    }
    dfs(A * 2, B);
    dfs(A * 10 + 1, B);
}

void solve()
{
    cin >> A >> B;
    flat = false;
    dfs(A, B);
    cout << (flat ? "YES" : "NO") << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> Q;
    while(Q--) solve();
    return 0;
}
