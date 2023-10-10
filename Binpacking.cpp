#include    <bits/stdc++.h>
#define ll long long
#define fo(i,d,c) for(int i=d;i<=c;i++)
#define sz(x) (int)x.size()
#define bit(i,j) ((i>>j)&1)
#define ii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int n, L;
ll a[mxN];

ii newSt(ii f, int cur, int x)
{
    ++f.fi;
    f.se += (cur + x > L);
    return f;
}

void minimize(ii &a, ii b)
{
    if (a > b || (a.fi == b.fi && a.se > b.se)) a = b;
}

ii f[1 << 20];

void sub1()
{

    f[0]= {1,0};
    for(int mask=1; mask<(1<<n); mask++)
    {
        f[mask]= {n+1,0};
        fo(i,0,n-1)
        {
            if(bit(mask,i))
            {
                ii option=f[mask^(1<<i)];
                if(option.se+a[i]<=L) option.se+=a[i];
                else
                {
                    option.fi++;
                    option.se=a[i];
                }
                f[mask]=min(f[mask],option);
            }
        }
    }
    cout<<f[(1<<n)-1].fi;
}

void sub2()
{
    int cnt[3]= {};
    fo(i,0,n-1) cnt[a[i]]++;
    int res=cnt[2]/50;
    res+=cnt[1]/100;
    if(cnt[1]%100+cnt[2]%50*2>L) res+=2;
    else if(cnt[1]%100+cnt[2]%50==0) res+=0;
    else res+=1;
    cout<<res;
}

int dp[10001][31][31];
void sub3()
{
    memset(dp, 0x3f3f, sizeof(dp));
    dp[0][0][0]=2;
    fo(i,0,n-1) fo(l1,0,30) fo(l2,0,30)
    {
        if(l2+a[i] <= L) dp[i+1][l1][l2+a[i]] = min(dp[i+1][l1][l2+a[i]], dp[i][l1][l2]);
        else dp[i+1][l1][a[i]] =min ( dp[i+1][l1][a[i]], dp[i][l1][l2]+1);
        if(l1+a[i] <= L) dp[i+1][l1+a[i]][l2] = min( dp[i+1][l1+a[i]][l2], dp[i][l1][l2]);
        else dp[i+1][a[i]][l2] = min( dp[i+1][a[i]][l2], dp[i][l1][l2]+1);
    }
    int res=INF;
    fo(i,0,30) fo(j,0,30) res=min(dp[n][i][j],res);
    cout<<res;
}

ii next(ii tmp,int val)
{
    if(tmp.se+val<=L) tmp.se+=val;
    else
    {
        tmp.fi++;
        tmp.se=val;
    }
    return tmp;
}

void sub5()
{
    vector<vector<ii>> dp(n + 1, vector<ii>(L + 1));
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=L; j++)
        {
            dp[i][j] = mp(INF, INF);
        }
    }

    dp[0][0] = mp(2, 0);
    for(int i=0; i<n; i++)
    {
        for(int l1=0; l1<=L; l1++)
        {
            if (l1 + a[i] > L)
            {
                minimize(dp[i + 1][a[i]], mp(dp[i][l1].fi + 1, dp[i][l1].se));
            } else
            {
                minimize(dp[i + 1][l1 + a[i]], dp[i][l1]);
            }

            ii tp = (dp[i][l1].se + a[i] <= L ? mp(dp[i][l1].fi, dp[i][l1].se + a[i]) : mp(dp[i][l1].fi + 1, a[i]));
            minimize(dp[i + 1][l1], tp);
        }
    }

    int ans = INF;
    for(int l=0; l<=L; l++)
    {
        ans = min(ans, dp[n][l].fi);
    }
    cout << ans;
}

void solve()
{
    cin >> L >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    if (n < 20) sub1();
     else if (L == 100) sub2();
      else if (L <= 30) sub3();
       else sub5();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
