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
const int block = 350;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

int N, numBlocks, a[mxN], b[mxN], lz[block], seg[block][mxN], L[block], R[block];

void upd(int u, int v)
{
    int pos = (u + block - 1) / block;
    for(int i=1; i<pos; i++)
    {
        lz[i] += v;
    }

    for(int i=L[pos]; i<=u; i++)
    {
        --seg[pos][b[i]];
        b[i] += v;
        ++seg[pos][b[i]];
    }
}

ll get(int l, int r)
{
    int posL = (l + block - 1) / block;
    int posR = (r + block - 1) / block;

    ll ret = 0;
    if (posL == posR)
    {
        for(int i=l; i<=r; i++)
        {
            ret += (b[i] + lz[posL] == r);
        }
        return ret;
    }

    for(int i=l; i<=R[posL]; i++)
    {
        ret += (b[i] + lz[posL] == r);
    }

    for(int i=posL+1; i<posR; i++)
    {
        ret += seg[i][r - lz[i]];
    }

    for(int i=L[posR]; i<=r; i++)
    {
        ret += (b[i] + lz[posR] == r);
    }
    return ret;
}

void solve()
{
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        cin >> a[i];
    }

    set0(R);
    int numBlock = (N + block - 1) / block;
    for(int i=1; i<=numBlock; i++)
    {
        L[i] = R[i - 1] + 1;
        R[i] = min(N, L[i] + block - 1);
    }

    for(int i=1; i<=numBlock; i++)
    {
        for(int j=L[i]; j<=R[i]; j++)
        {
            b[j] = j;
            seg[i][j]++;
        }
    }

    int l = 1;
    ll ans = 0;
    vector<int> pref_max(N + 1, 0), pref_min(N + 1, 0), Lmax(N + 1, 0), Lmin(N + 1, 0), appear(N + 1, 0);
    for(int i=1; i<=N; i++)
    {
        Lmax[i] = i - 1;
        while(Lmax[i] > 0 && a[i] >= a[Lmax[i]])
        {
            Lmax[i] = Lmax[Lmax[i]];
            upd(Lmax[i], -pref_max[Lmax[i]]);
            pref_max[Lmax[i]] = 0;
        }

        if (Lmax[i] > 0)
        {
            pref_max[Lmax[i]] = a[Lmax[i]] - a[i];
            upd(Lmax[i], pref_max[Lmax[i]]);
        }

        Lmin[i] = i - 1;
        while(Lmin[i] > 0 && a[i] <= a[Lmin[i]])
        {
            Lmin[i] = Lmin[Lmin[i]];
            upd(Lmin[i], -pref_min[Lmin[i]]);
            pref_min[Lmin[i]] = 0;
        }

        if (Lmin[i] > 0)
        {
            pref_min[Lmin[i]] = a[i] - a[Lmin[i]];
            upd(Lmin[i], pref_min[Lmin[i]]);
        }

        l = max(l, appear[a[i]] + 1);
        appear[a[i]] = i;
        ans += get(l, i);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif //SKY
    solve();
    return 0;
}

