#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 1e5 + 66;

int n;
vector<ii> job;

void solve()
{
    cin >> n;
    job.resize(n);
    for(int i=0; i<n; i++)
    {
        cin >> job[i].fi >> job[i].se;
    }

    sort(all(job), greater<ii>());

    ll pos = 0, ans = 0;
    priority_queue<ll> pq;
    while(job[pos].fi > n)
    {
        pq.push(job[pos++].se);
    }

    for(int curT=n; curT>0; curT--)
    {
        while(pos < n && curT == job[pos].fi)
        {
            pq.push(job[pos++].se);
        }

        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
