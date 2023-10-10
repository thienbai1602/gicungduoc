#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

int n, Q, odd[mxN], even[mxN];

ll ck(int k, int n)
{
    ll ans = 1, g = 1;
    for(; k>0; k--)
    {
        ans *= n;
        g *= k;
        --n;
    }
    return ans / g;
}

void solve()
{
    cin >> n >> Q;
    set0(odd), set0(even);
    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        odd[i] = odd[i - 1], even[i] = even[i - 1];
        if (x & 1) ++odd[i];
         else ++even[i];
    }

    while(Q--)
    {
        int l, r;
        cin >> l >> r;
        int curOdd = odd[r] - odd[l - 1];
        int curEven = even[r] - even[l - 1];
        cout << ck(3, curEven) + curEven * ck(2, curOdd) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
