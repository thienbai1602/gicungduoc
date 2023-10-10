#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int n, K;

void solve()
{
    cin >> n >> K;
    vector<ll> task(n + 2), pref(n + 2, 0);
    for(int i=1; i<=n; i++)
    {
        cin >> task[i];
    }

    for(int i=0; i<K; i++)
    {
        int pos;
        cin >> pos;
        task[pos]--;
    }

    for(int i=1; i<=n; i++)
    {
        cout << task[i] + K << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
