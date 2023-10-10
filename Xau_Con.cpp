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

int pi[mxN];
string A, B;

void solve()
{
    cin >> A >> B;
    pi[0] = 0;
    for(int i=1, j=0; i<sz(B); i++)
    {
        while(j > 0 && B[i] != B[j])
        {
            j = pi[j - 1];
        }
        j += (B[i] == B[j]);
        pi[i] = j;
    }

    int i = 0, j = 0;
    while(i < sz(A))
    {
        if (A[i] == B[j])
        {
            ++i, ++j;
            if (j == sz(B)) cout << i - j + 1 << " ";
        } else if (j > 0) j = pi[j - 1];
         else ++i;
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

