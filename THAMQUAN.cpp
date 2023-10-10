#include	<bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 3e4 + 55;

struct Bus
{
	ll val, id;
};

int n, m, cnt[mxN];
Bus cus[mxN], taxi[mxN];

bool cmp(Bus a, Bus b)
{
	return a.val < b.val; 
}

bool cmp1(Bus a, Bus b)
{
	return a.val > b.val;
}

void solve()
{
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		cin >> cus[i].val;
		cus[i].id = i;
	}
	
	for(int i=0; i<m; i++)
	{
		cin >> taxi[i].val;
		taxi[i].id = i;
	}
	
	sort(cus, cus + n, cmp1);
	sort(taxi, taxi + m, cmp);
	
	ll ret = 0;
	for(int i=0; i<n; i++)
	{
		ret += cus[i].val * taxi[i].val;
		cnt[cus[i].id] = taxi[i].id;
	}
	
	cout << ret << "\n";
	for(int i=0; i<n; i++)
	{
		cout << cnt[i] + 1 << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("THAMQUAN.INP", "r", stdin);
	freopen("THAMQUAN.OUT", "w", stdout);
	solve();
	return 0;
}

