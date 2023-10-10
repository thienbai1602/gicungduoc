#include    <bits/stdc++.h>
//#define SKY
#define ll long long
#define ld long double
#define MASK(x) (1LL << x)
#define sz(x) (int)x.size()
#define pi pair<int, int>
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
const int block = 700;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

struct query
{
    int l, r, idx, k;
    query(int l, int r, int idx, int k) : l(l), r(r), idx(idx), k(k){
    }

    bool operator < (const query v)
    {
        return mp(l / block, r) < mp(v.l / block, v.r);
    }
};

vector<query> seg;
vector<int> edges[mxN];
int N, Q, cnt[mxN], freq[mxN], bucket[mxN], represent[mxN], col[mxN], in[mxN], out[mxN], timer = 0;

void euler_tour(int u, int p)
{
    in[u] = ++timer;
    represent[timer] = u;
    for(int v : edges[u])
    {
        if (v == p) continue;
        euler_tour(v, u);
    }
    out[u] = timer;
}

int getBlock(int B)
{
    return (B + block - 1) / block;
}

int get(int lo, int hi)
{
    int L = getBlock(lo), R = getBlock(hi), ret = 0;
    if (L == R)
    {
        for(int i=lo; i<=hi; i++)
        {
            ret += freq[i];
        }
        return ret;
    }

    for(int i=lo; i<=L*block; i++)
    {
        ret += freq[i];
    }

    for(int i=R*block; i<=hi; i++)
    {
        ret += freq[i];
    }

    for(int i=L+1; i<R; i++)
    {
        ret += bucket[i];
    }
    return ret;
}

void add(int pos)
{
    int u = represent[pos];
    int c = col[u];
    freq[cnt[c]]--;
    bucket[getBlock(cnt[c])]--;
    ++cnt[c];
    freq[cnt[c]]++;
    bucket[getBlock(cnt[c])]++;
}

void removing(int pos)
{
    int u = represent[pos];
    int c = col[u];
    freq[cnt[c]]--;
    bucket[getBlock(cnt[c])]--;
    --cnt[c];
    freq[cnt[c]]++;
    bucket[getBlock(cnt[c])]++;
}

void solve()
{
    cin >> N >> Q;
    for(int i=0; i<N; i++)
    {
        cin >> col[i];
    }

    for(int i=0; i<N-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    euler_tour(0, -1);
    for(int i=0; i<Q; i++)
    {
        int node, color;
        cin >> node >> color;
        --node;
        seg.pb(query(in[node], out[node], i, color));
    }

    /*for(int i=1; i<=N; i++)
    {
        cout << represent[i] << (i < N ? " " : "\n");
    }*/

    sort(all(seg));
    /*for(int i=0; i<sz(seg); i++)
    {
        cout << seg[i].idx << " " << seg[i].l << " " << seg[i].r << "\n";
    }*/

    vector<int> ans(Q, 0);
    int lo = 1, hi = 0;
    for(auto [l, r, idx, k] : seg)
    {
        while(hi < r)
        {
            hi++;
            add(hi);
        }

        while(lo > l)
        {
            --lo;
            add(lo);
        }

        while(hi > r)
        {
            removing(hi);
            --hi;
        }

        while(lo < l)
        {
            removing(lo);
            ++lo;
        }

        /*cout << lo << " " << hi << " " << l << " " << r << " " << k << "\n";
        for(int i=1; i<=N; i++)
        {
            cout << freq[i] << (i < N ? " " : "\n");
        }*/
        ans[idx] = get(k, N);
    }

    for(int &x : ans) cout << x << "\n";
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
