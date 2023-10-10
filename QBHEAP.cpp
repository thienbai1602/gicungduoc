#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
using namespace std;

string S;
priority_queue<ll> pq;

void solve()
{
    while(cin >> S)
    {
        if (S[0] == '+')
        {
            if (sz(pq) < 15000)
            {
                ll x = 0;
                for(int i=1; i<sz(S); i++)
                {
                    x = x * 10 + (S[i] - '0');
                }
                pq.push(x);
            }
        } else
        {
            if (sz(pq) != 0)
            {
                ll x = pq.top();
                while(!pq.empty() && x == pq.top())
                {
                    pq.pop();
                }
            }
        }
    }

    ll prev = 0;
    vector<ll> ret;
    while(!pq.empty())
    {
        ll x = pq.top();
        pq.pop();
        if (prev == x) continue;
        ret.pb(x);
        prev = x;
    }

    cout << sz(ret) << "\n";
    for(ll &x : ret) cout << x << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
