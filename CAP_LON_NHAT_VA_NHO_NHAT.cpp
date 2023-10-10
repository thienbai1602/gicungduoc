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

int L, S;
string x, y;
bool flat = true;

void number_min()
{
    string a;
    int curS = 0;
    for(int i=0; i<L; i++)
    {
        if (i == 0) a.pb('1');
         else a.pb('0');
        curS += (i == 0);
    }

    if (curS == S)
    {
        x = a;
        return;
    }

    if (curS > S)
    {
        flat = false;
        return;
    }

    int l = (S - curS) / 9;
    for(int pos=L-l; pos<L; pos++, curS+=9)
    {
        a[pos] = '9';
    }

    if (curS < S)
    {
        a[L - l - 1] += (S - curS);
    }
    x = a;
}

void number_max()
{
    string b;
    for(int i=0, curS=0; i<L; i++)
    {
        if (curS + 9 <= S)
        {
            b.pb('9');
            curS += 9;
        } else
        {
            if (S - curS < 9)
            {
                char digit = (char)(S - curS + '0');
                b.pb(digit);
                curS = S;
            } else flat = false;
        }
    }
    y = b;
}

void solve()
{
    cin >> L >> S;
    if (L * 9 < S)
    {
        cout << "-1";
        return;
    }
    number_min();
    number_max();
    if (!flat) cout << "-1";
     else cout << x << "\n" << y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
