#include    <bits/stdc++.h>
//#define SKY
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

string a, b;

void solve()
{
    cin >> a >> b;
    string ans = "";
    int x = -1, y = -1;
    for(char chr='z'; chr>='a'; chr--)
    {
        while(1)
        {
            bool ok = false;
            int u, v;
            for(int i=x+1; i<sz(a); i++)
            {
                if (a[i] == chr)
                {
                    u = i;
                    ok = true;
                    break;
                }
            }

            if (!ok) break;
            ok = false;
            for(int i=y+1; i<sz(b); i++)
            {
                if (b[i] == chr)
                {
                    v = i;
                    ok = true;
                    break;
                }
            }

            if (!ok) break;
            x = u, y = v;
            ans = ans + a[x];
        }
    }
    cout << (sz(ans) ? ans : "-1");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif //SKY
    solve();
    return 0;
}
