#include	<bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e5 + 66;

int n, m, cnt, ct = 0;
bool vis[mxN];
stack<int> st;
vector<int> edges[mxN];
int low[mxN], num[mxN], x[mxN], y[mxN], zNode[mxN], tp[mxN], dp[mxN];

void be_nhanh(int u)
{
	zNode[ct] = 1;
	while(st.top() != u)
	{
		int v = st.top();
		vis[v] = true;
		zNode[ct]++;
		tp[v] = ct;
		st.pop();
	}
	vis[u] = true;
	tp[u] = ct;
	st.pop();
	++ct;
}

void tarjan(int u)
{
	st.push(u);
	low[u] = num[u] = ++cnt;
	for(int i=0; i<sz(edges[u]); i++)
	{
		int v = edges[u][i];
		if (!vis[v])
		{
			if (num[v]) low[u] = min(low[u], num[v]);
			 else 
			 {
			 	tarjan(v);
			 	low[u] = min(low[u], low[v]);
			 }
		}
	}
	if (num[u] == low[u]) be_nhanh(u);
}

void new_graph()
{
	for(int i=0; i<n; i++) edges[i].clear();
	
	for(int i=0; i<m; i++)
	{
		if (tp[x[i]] != tp[y[i]])
		{
			edges[tp[x[i]]].push_back(tp[y[i]]);
		}
	}
}

void dfs(int u)
{
	vis[u] = true;
	dp[u] = zNode[u];
	for(int i=0; i<sz(edges[u]); i++)
	{
		int v = edges[u][i];
		if (!vis[v])
		{
			dfs(v);
		}
		dp[u] += dp[v];
	}
}

void solve()
{
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		cin >> x[i] >> y[i];
		edges[--x[i]].push_back(--y[i]);
	}
	
	memset(vis, false, sizeof(vis));
	for(int i=0; i<n; i++)
	{
		if (!vis[i])
		{
			cnt = 0;
			tarjan(i);
		}
	}
	
	new_graph();
	memset(vis, false, sizeof(vis));
	for(int i=0; i<ct; i++)
	{
		if (!vis[i])
		{
			dfs(i);
		}
	}
	
	for(int i=0; i<n; i++)
	{
		cout << dp[tp[i]] - 1 << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
