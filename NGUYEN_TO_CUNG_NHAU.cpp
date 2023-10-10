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

const ll INF = 1e18;
const int mxN = 1e6 + 66;

bool isPrime[mxN];
int n, M, cnt[mxN];

void solve()
{
    cin >> n >> M;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        ++cnt[x];
    }

    vector<int> p;
    memset(isPrime, false, sizeof(isPrime));
    for(int i=2; i<=(ll)1e6+6; i++)
    {
        if (!isPrime[i])
        {
            bool ok = false;
            for(int j=i; j<=(ll)1e6+6; j+=i)
            {
                isPrime[j] = true;
                if (cnt[j] && !ok)
                {
                    p.pb(i);
                    ok = true;
                }
            }
        }
    }

    memset(isPrime, false, sizeof(isPrime));
    for(int &x : p)
    {
        for(int j=x; j<=(ll)1e6+6; j+=x)
        {
            isPrime[j] = true;
        }
    }

    vector<int> ans;
    for(int x=1; x<=M; x++)
    {
        if (!isPrime[x])
        {
            ans.pb(x);
        }
    }

    cout << sz(ans) << "\n";
    for(int &x : ans) cout << x << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
