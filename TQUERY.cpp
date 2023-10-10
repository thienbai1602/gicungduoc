#include    <bits/stdc++.h>
//#define SKY
#define ll long long
#define ld long double
#define MASK(x) (1LL << x)
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

struct Trie
{
    Trie *child[2];
    ll cnt, S;
    Trie()
    {
        cnt = 0, S = 0;
        set0(child);
    }
};

int Q;
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
        p -> S += x;
    }
}

ll findVal(ll x)
{
    Trie *p = root;
    for(int i=32; i>=0; i--)
    {
        int bit = (x >> i) & 1;
        if (p -> child[bit] == NULL) return 0;
        p = p -> child[bit];
    }
    return p -> cnt;
}

void deleteVal(ll x)
{
    if (!findVal(x)) return;
    Trie *p = root;
    for(int i=32; i>=0; i--)
    {
        int bit = (x >> i) & 1;
        p = p -> child[bit];
        p -> cnt--;
        p -> S -= x;
    }
}

ll getS(ll x)
{
    ll ans = 0;
    Trie *p = root;
    if (x <= 0) return 0;
    for(int i=32; i>=0; i--)
    {
        int bit = (x >> i) & 1;
        if (bit)
        {
            if (p -> child[!bit] != NULL) ans += (p -> child[!bit]) -> S;
        }

        if (p -> child[bit] != NULL && (p -> child[bit]) -> cnt > 0)
        {
            p = p -> child[bit];
        } else break;
    }
    return ans + findVal(x) * x;
}

ll findK(ll k)
{
    ll ct = 0;
    ll ans = 0;
    Trie *p = root;
    for(int i=32; i>=0; i--)
    {
        if (p -> child[0] != NULL && (p -> child[0]) -> cnt + ct >= k)
        {
            p = p -> child[0];
        } else
        {
            ans += MASK(i);
            ct += (p -> child[0] != NULL ? (p -> child[0]) -> cnt : 0);
            p = p -> child[1];
        }
    }
    return ans;
}

ll maxor(ll a)
{
    ll ans = 0;
    Trie *p = root;
    for(int i=32; i>=0; i--)
    {
        int bit = (a >> i) & 1;
        if (p -> child[!bit] != NULL && (p -> child[!bit]) -> cnt > 0)
        {
            ans += MASK(i);
            p = p -> child[!bit];
        } else
        {
            if (p -> child[bit] == NULL || (p -> child[bit]) -> cnt == 0) break;
            p = p -> child[bit];
        }
    }
    return ans;
}

void solve()
{
    cin >> Q;
    while(Q--)
    {
        int type;
        cin >> type;
        switch(type)
        {
        case 1:
            {
                ll x;
                cin >> x;
                add(x);
                break;
            }
        case 2:
            {
                ll x;
                cin >> x;
                deleteVal(x);
                break;
            }
        case 3:
            {
                ll L, R;
                cin >> L >> R;
                cout << getS(R) - getS(L - 1) << "\n";
                break;
            }
        case 4:
            {
                ll k;
                cin >> k;
                cout << findK(k) << "\n";
                break;
            }
        default:
            {
                ll a;
                cin >> a;
                cout << maxor(a) << "\n";
            }
        }
    }
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
