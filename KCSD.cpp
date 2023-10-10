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

int N, K;

string mul(string a, int b)
{
    string ret = "";
    for(ll i=sz(a)-1, carry=0; i>=0; i--)
    {
        ll digit = (int)(a[i] - '0') * b + carry;
        carry = digit / 10;
        ret = (char)(digit % 10 + '0') + ret;

        if (i == 0)
        {
            while(carry)
            {
                ret = (char)(carry % 10 + '0') + ret;
                carry /= 10;
            }
        }
    }
    return ret;
}

void solve()
{
    cin >> N >> K;
    string ans = "1";
    for(int x=1; x<=N; x++)
    {
        ans = mul(ans, x);
    }

    for(int i=0; i<K; i++) cout << ans[i];
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
