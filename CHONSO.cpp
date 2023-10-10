#include	<bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e3 + 66;

int n, pos;
vector<int> path;
ll a[mxN], dp[mxN];

void ans_path()
{
	while(pos > 0)
	{
		if (dp[pos] == dp[pos - 1])
		{
			pos--;
			continue;
		}
		
		if (dp[pos] == a[pos] + dp[pos - 2])
		{
			path.push_back(pos);
			pos -= 2;
		} else
		{
			path.push_back(pos);
			path.push_back(pos - 1);
			pos -= 3;
		}
	}
}

void truy_vet()
{
	pos = -1;
	ll ret = 0;
	for(int i=1; i<=n; i++)
	{
		if (ret < dp[i])
		{
			ret = dp[i];
			pos = i;
		}
	}
	
	ans_path();
	cout << ret << " " << sz(path) << "\n";
	for(int i=sz(path)-1; i>=0; i--)
	{
		cout << path[i] << "\n";
	}
}

void solve()
{ 
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	
	dp[1] = a[1], dp[2] = a[1] + a[2];
	for(int i=3; i<=n; i++)
	{
		dp[i] = dp[i - 1];
		dp[i] = max(dp[i], max(dp[i - 2] + a[i], a[i] + a[i - 1] + dp[i - 3]));		
	}
	truy_vet();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("CHONSO.INP", "r", stdin);
	freopen("CHONSO.OUT", "w", stdout);
	solve();
	return 0;
}
