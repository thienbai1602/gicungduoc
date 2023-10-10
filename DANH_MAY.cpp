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
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

struct Trie
{
    Trie* child[26];
    int cnt, exist;

    Trie()
    {
        cnt = exist = 0;
        set0(child);
    }
};

Trie* root = new Trie();

void add_string(string s)
{
    Trie* p = root;
    for(char &c : s)
    {
        if (p -> child[c - 'a'] == NULL) p -> child[c - 'a'] = new Trie();
        p = p -> child[c - 'a'];
        p -> cnt++;
    }
    p -> exist++;
}

ll query(string s)
{
    ll ret = 0;
    Trie* p = root;
    for(char &c : s)
    {
        if (p -> child[c - 'a'] == NULL) break;
        p = p -> child[c - 'a'];
        ret += p -> exist;
    }
    return ret;
}

int n;
vector<string> S;

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string s;
        cin >> s;
        S.pb(s);
    }

    sort(all(S));
    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += query(S[i]);
        add_string(S[i]);
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
