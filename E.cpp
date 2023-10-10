#include    <bits/stdc++.h>
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

int tc, n, m;
string s;

int get(vector<int> &a)
{
    int cnt = 0;
    vector<char> dau;
    vector<int> express;
    for(char &chr : s)
    {
        if (chr == '+' || chr == '-' || chr == '*')
        {
            dau.pb(chr);
            continue;
        }

        if (chr >= 'a' && chr <= 'z')
        {
            express.pb(a[cnt++]);
            continue;
        }

        if (chr == ')')
        {
            int B = express.back();
            express.pop_back();
            int A = express.back();
            express.pop_back();

            if (dau.back() == '+')
            {
                A += B;
            }

            if (dau.back() == '-')
            {
                A -= B;
            }

            if (dau.back() == '*')
            {
                A *= B;
            }
            dau.pop_back();
            express.pb(A);
        }
    }
    return express.back();
}

bool sol(vector<int> &a)
{
    sort(all(a));
    do
    {
        if (get(a) == m) return true;
    } while(next_permutation(all(a)));
    return false;
}

void solve()
{
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    cin >> m >> s;
    cout << (sol(a) ? "YES" : "NO") << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
