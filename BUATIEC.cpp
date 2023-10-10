#include	<bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 2066;

int n;
bool vis[mxN];
int funny[mxN], height[mxN];
vector<int> edges[mxN];

void dfs(int u)
{
	vis[u] = true;
	for(int i=0; i<sz(edges[u]); i++)
	{
		int v = edges[u][i];
		if (!vis[v])
		{
			height[v] = height[u] + 1;
			dfs(v);
		}
	}
}

ll new_root(int root)
{
	memset(height, 0, sizeof(height));
	memset(vis, false, sizeof(vis));
	dfs(root);
	
	ll even = 0, odd = 0;
	for(int i=0; i<n; i++)
	{
		if (height[i] % 2 == 0)
		{
			even += funny[i];
		} else
		{
			odd += funny[i];
		}
	}
	return max(even, odd);
}

void solve()
{
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> funny[i];
	}
	
	for(int i=0; i<n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	
	ll ret = 0;
	for(int i=0; i<n; i++)
	{
		ret = max(ret, new_root(i));
	}
	cout << ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("BUATIEC.INP", "r", stdin);
	freopen("BUATIEC.OUT", "w", stdout);
	solve();
	return 0;
}
