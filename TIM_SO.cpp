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

int N, d[305];
string m, ans;

bool operator < (string& a, string& b)
{
    if (sz(a) < sz(b)) return true;
    if (sz(a) > sz(b)) return false;
    for(int i=0; i<sz(a); i++)
    {
        if (a[i] > b[i]) return false;
        if (a[i] < b[i]) return true;
    }
    return false;
}

void backTrack(string cur, int k)
{
    if (k == sz(m) + 1)
    {
        if (m < cur && cur < ans)
        {
            ans = cur;
        }
        return;
    }

    for(char c='0'; c<='9'; c++)
    {
        if (c == '0' && k == 0) continue;
        if (d[c])
        {
            d[c] = 0;
            cur += c;
            if (m < cur && cur < ans) ans = cur;
            backTrack(cur, k + 1);
            cur.pop_back();
            d[c] = 1;
        }
    }
}

void solve()
{
    cin >> N >> m;
    for(int i=0; i<N; i++)
    {
        char c;
        cin >> c;
        ++d[c];
    }

    int sz = 0;
    for(char c='0'; c<='9'; c++)
    {
        sz += (d[c] > 0);
    }

    int szM = sz(m);
    if (sz < szM)
    {
        cout << "Khong tim duoc";
        return;
    }

    ans = "";
    if (sz == szM)
    {
        for(char c='9'; c>='0'; c--)
        {
            if (d[c])
            {
                ans += c;
            }
        }
        if (ans <= m)
        {
            cout << "Khong tim duoc";
            return;
        }
    }

    if (sz > szM)
    {
        for(char c='0'; c<='9'; c++)
        {
            ans += c;
        }

        if (ans[0] == '0')
        {
            swap(ans[0], ans[1]);
        }
    }
    backTrack("", 0);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
