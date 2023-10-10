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

int n;
ll a[mxN];

void quicksort(int l, int r)
{
    if (l <= r)
    {
        int i = l, j = r;
        ll key = a[(l + r) >> 1];
        while(i <= j)
        {
            while(a[i] < key) ++i;
            while(a[j] > key) --j;
            if (i <= j)
            {
                swap(a[i], a[j]);
                if (i != j) cout << i + 1 << " " << j + 1 << "\n";
                ++i, --j;
            }
        }

        if (l < j) quicksort(l, j);
        if (i < r) quicksort(i, r);
    }
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    quicksort(0, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
