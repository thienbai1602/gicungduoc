#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 1e5 + 66;

int N;
ll a[mxN], b[mxN];
map<ll, ll> lineY, lineX;

void solve()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> a[i] >> b[i];
        ++lineX[a[i]];
        ++lineY[b[i]];
    }

    ll ret = 0;
    for(int i=0; i<N; i++)
    {
        ret += (lineX[a[i]] - 1) * (lineY[b[i]] - 1);
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
