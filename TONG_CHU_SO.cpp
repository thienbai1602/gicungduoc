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

int tc;
string S;

void out(vector<char> nxt)
{
    bool ok = false;
    for(char &c : nxt)
    {
        if (c == '0' && !ok) continue;
        cout << c;
        ok = true;
    }
}

void solve()
{
    cin >> S;
    int T = 0;
    vector<int> num;
    for(char &c : S)
    {
        num.pb(c - '0');
        T += num.back();
    }

    if (!(T & 1))
    {
        vector<char> A, B;
        int tcsA = 0, tcsB = 0;
        for(int &digit : num)
        {
            if (!(digit & 1))
            {
                tcsA += digit / 2, tcsB += digit / 2;
                A.pb((char)(digit / 2 + ' 0'));
                B.pb((char)(digit / 2 + ' 0'));
            } else
            {
                tcsA += (digit + 1) / 2, tcsB += (digit - 1) / 2;
                A.pb((char)((digit + 1) / 2 + '0'));
                B.pb((char)((digit - 1) / 2 + '0'));
            }

            if (tcsA > tcsB)
            {
                swap(tcsA, tcsB);
                swap(A, B);
            }
        }

        out(A);
        cout << " ";
        out(B);
        cout << "\n";
    } else
    {
        vector<char> A, B;
        bool modify = false;
        int tcsA = 0, tcsB = 0;
        for(int i=0; i<sz(num); i++)
        {
            if (i != sz(num) - 1 && !modify && num[i] > 0 && num[i + 1] < 9)
            {
                num[i]--;
                num[i + 1] += 10;
                modify = true;
            }

            int digit = num[i];
            if (!(digit & 1))
            {
                tcsA += digit / 2;
                tcsB += digit / 2;
                A.pb((char)(digit / 2 + '0'));
                B.pb((char)(digit / 2 + '0'));
            } else
            {
                tcsA += (digit + 1) / 2;
                tcsB += (digit - 1) / 2;
                A.pb((char)((digit + 1) / 2 + '0'));
                B.pb((char)((digit - 1) / 2 + '0'));
            }

            if (tcsA > tcsB)
            {
                swap(tcsA, tcsB);
                swap(A, B);
            }
        }

        if (!modify || A.empty() || B.empty()) cout << "-1\n";
         else
         {
             out(A);
             cout << " ";
             out(B);
             cout << "\n";
         }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    cin >> tc;
    while(tc--) solve();
    return 0;
}

