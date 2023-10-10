#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int,int> pii;
const int64_t p = 1e9 + 7;
int n,m,k,x,y,u=1,v=0,ib=0;
int64_t ft[2000001],dp[2005][2005];
vector<pii>ob;
int64_t ans,r;
int64_t pw(int64_t u)
{
int64_t res=1,tm=u, tp=p-2;
while(tp)
{
if(tp&1)res=res*tm%p;
tm=tm*tm%p;
tp>>=1;
}
return res;
}
int64_t comb(int u, int v)
{
int64_t a,b,c;
int q=u+v;
u=min(u,v);
a=ft[q]; b= ft[u]*ft[q-u]%p;
b=pw(b);
return a*b%p;
}
int get_cb(int i, int j, int u)
{
if((ob[u].ss > ob[j].ss)||(ob[u].ss < ob[i].ss)) return 0;
x=ob[j].ff-ob[u].ff;
y=ob[j].ss-ob[u].ss;
if(x==0 || y==0) return 1;
return comb(x,y);
}
int all_r(int i, int j)
{
x=ob[j].ff-ob[i].ff;y=ob[j].ss-ob[i].ss;
if(y<0) return 0;
if(x==0 || y==0) if(i+1==j) return 1;
return comb(x,y);
}
int main()
{
cin>>n>>m>>k;
ob.resize(k);
ft[0]=1;
for(int i=1; i<=2000000; ++i) ft[i]=ft[i-1]*i%p;
for(int i=0; i<k; ++i)
{
cin>>x>>y; --x; --y;
ob[i]={x,y};
}
ob.push_back({0,0}); ob.push_back({n-1,m-1});
sort(ob.begin(),ob.end());
for(int t=1;t<=k;++t)
for(int i=0; i<=k-t; ++i)
{
int j=i+t;
r=0;
for(int it=i+1; it<j; ++it)
r=(r+dp[i][it]*get_cb(i,j,it))%p;
dp[i][j]=(all_r(i,j)-r)%p;
}
r=0;
for(int it=1; it<=k; ++it)
r=(r+dp[0][it]*get_cb(0,k+1,it))%p;
ans = (comb(n-1,m-1)-r+p)%p;
cout<<ans;
}
