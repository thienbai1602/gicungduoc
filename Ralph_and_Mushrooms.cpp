#include	<bits/stdc++.h>
#define ll long long
#define ld long double
#define ii pair<ll, ll>
#define fi first
#define se second
#define sz(x) (int)x.size()
#define mp make_pair
using namespace std;

const ll INF = 1e18;
const int mxN = 1e6 + 66;

int n, m, s, cnt, ct = 0;
bool vis[mxN];
stack<int> st;
map<ii, ll> mush;
vector<int> revTopo;
vector<ii> edges[mxN], g[mxN];
ll dp[mxN], pref[mxN], low[mxN], num[mxN], tp[mxN], mushroom[mxN], ind[mxN];

ll bs(ll l, ll r, ll x)
{
    int ps = -1;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        ll s = (m + 1) * m / 2;
        if (x - s >= 0)
        {
            ps = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    return ps;
}

ll cal(ll x)
{
	ll pos = bs(0, 100000, x);
	return x * (pos + 1) - pref[pos];
}

void be_nhanh(int u)
{
	while(st.top() != u)
	{
		int v = st.top();
		vis[v] = true;
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
	for(auto [w, v] : edges[u])
	{
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
	if (low[u] == num[u]) be_nhanh(u);
}

void new_graph()
{
	for(int u=0; u<n; u++)
	{
		for(auto [w, v] : edges[u])
        {
            if (tp[u] == tp[v])
            {
                mushroom[tp[u]] += cal(w);
            }
        }
	}

	for(int u=0; u<n; u++)
    {
		for(auto [w, v] : edges[u])
		{
		    if (tp[u] != tp[v])
            {
                ind[tp[v]]++;
                g[tp[u]].push_back(mp(w, tp[v]));
            }
		}
	}
}

void dfs(int u)
{
	vis[u] = true;
	for(auto [w, v] : g[u])
	{
		if (!vis[v])
		{
			dfs(v);
		}
	}
	revTopo.push_back(u);
}

void solve()
{
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		edges[u].push_back(mp(w, v));
	}
	cin >> s;
	--s;

	pref[0] = 0;
	for(ll i=1; i<100001; i++)
    {
        pref[i] = pref[i - 1] + (i + 1) * i / 2;
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

	memset(ind, 0, sizeof(ind));
	new_graph();
	memset(vis, false, sizeof(vis));
	dfs(tp[s]);

    reverse(revTopo.begin(), revTopo.end());
    for(int i=0; i<ct; i++)
    {
        dp[i] = -INF;
    }

    ll ret = mushroom[tp[s]];
    dp[tp[s]] = mushroom[tp[s]];
    for(int u : revTopo)
    {
        for(auto [w, v] : g[u])
        {
            dp[v] = max(dp[v], dp[u] + mushroom[v] + w);
            ret = max(ret, dp[v]);
        }
    }
    cout << ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
