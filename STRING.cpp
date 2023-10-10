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

string S;
int n, nxt[mxN][30], sl[mxN][30], need[30];

bool can_build(int t)
{
    for(int c=0; c<26; c++)
    {
        if (need[c] > sl[t][c]) return false;
    }
    return true;
}

void solve()
{
    cin >> S;
    n = sz(S);
    set0(nxt), set0(sl);
    for(int i=1; i<=n; i++)
    {
        for(int c=0; c<26; c++)
        {
            nxt[i][c] = nxt[i - 1][c];
            sl[i][c] = sl[i - 1][c];
        }
        ++sl[i][S[i -1] - 'a'];
        nxt[i][S[i - 1] - 'a'] = i;
    }

    for(int c=0; c<26; c++)
    {
        need[c] = sl[n][c] / 2;
    }

    string ans;
    int pref = n;
    for(int i=0; i<n/2; i++)
    {
        for(int c=0; c<26; c++)
        {
            if (need[c])
            {
                int id = nxt[pref][c];
                if (!id) continue;
                --need[c];
                if (can_build(id - 1))
                {
                    ans += (char)(c + 'a');
                    pref = id - 1;
                    break;
                }
                ++need[c];
            }
        }
    }
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
