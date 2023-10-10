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
const int mxN = 2e5 + 66;

struct Trie
{
    Trie *child[2];
    int cnt;
    Trie()
    {
        set0(child);
        cnt = 0;
    }
};
Trie *root = new Trie();

void add(ll x)
{
    Trie *p = root;
    for(int i=32; i>=0; i--)
    {
        int bit = (x >> i) & 1;
        if (p -> child[bit] == NULL) p -> child[bit] = new Trie();
        p = p -> child[bit];
        p -> cnt++;
    }
}

void del(ll x)
{
    Trie *p = root;
    for(int i=32; i>=0; i--)
    {
        int bit = (x >> i) & 1;
        p = p -> child[bit];
        p -> cnt--;
    }
}

ll query(ll x)
{
    ll ans = 0;
    Trie *p = root;
    for(int i=32; i>=0; i--)
    {
        int bit = (x >> i) & 1;
        if (p -> child[bit ^ 1] != NULL && p -> child[bit ^ 1] -> cnt > 0)
        {
            ans += (1LL << i);
            bit ^= 1;
        }
        if (p -> child[bit] == NULL) return x;
        p = p -> child[bit];
    }
    return max(ans, x);
}

int Q;

void solve()
{
    cin >> Q;
    while(Q--)
    {
        ll x;
        char c;
        cin >> c >> x;
        if (c == '+')
        {
            add(x);
        } else
         if (c == '-')
         {
             del(x);
         } else
         {
             cout << query(x) << "\n";
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

