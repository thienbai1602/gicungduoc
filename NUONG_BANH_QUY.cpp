#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

ll N, T;
map<ii, ll> ma;

void solve()
{
    cin >> N >> T;

    priority_queue<pair<ll, ii>, vector<pair<ll, ii>>, greater<pair<ll, ii>>> pq;
    pq.push(mp(0, mp(0, 1))); ma[mp(0, 1)] = 0;
    while(!pq.empty())
    {
        pair<ll, ii> nxt = pq.top();
        ll cur = nxt.fi;
        pq.pop();

        if (nxt.se.fi >= N)
        {
            cout << cur;
            break;
        }

        if (!ma[mp(nxt.se.fi + nxt.se.se, nxt.se.se)])
        {
            ma[mp(nxt.se.fi + nxt.se.se, nxt.se.se)] = 1;
            pq.push(mp(cur + 1, mp(nxt.se.fi + nxt.se.se, nxt.se.se)));
        }

        if (!ma[mp(0, nxt.se.fi)] && nxt.se.fi != 0)
        {
            ma[mp(0, nxt.se.fi)] = 1;
            pq.push(mp(cur + T, mp(0LL, nxt.se.fi)));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
