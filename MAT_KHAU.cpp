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
const int mxN = 1e6 + 66;

string A;
int n, pi[mxN], ct[mxN];

void solve()
{
    cin >> A;
    set0(pi), set0(ct);
    pi[0] = 0; n = sz(A);
    for(int i=1, j=0; i<n; i++)
    {
        while(j > 0 && A[i] != A[j])
        {
            j = pi[j - 1];
        }
        j += (A[i] == A[j]);
        pi[i] = j;
        ++ct[pi[i]];
    }

    --n;
    if (pi[n] > 0 && ct[pi[n]] > 1)
    {
        for(int i=0; i<pi[n]; i++)
        {
            cout << A[i];
        }
    } else
    {
        if (pi[pi[n] - 1] == 0) cout << "Just a legend";
         else
         {
             for(int i=0; i<pi[pi[n] - 1]; i++)
             {
                 cout << A[i];
             }
         }
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
