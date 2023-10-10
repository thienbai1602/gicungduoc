#include	<bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 2e5 + 66;

int n;
ll t[mxN], m, tot = 0;
vector<ll> employer[mxN];

bool check(ll tp)
{
	ll ma_employer = m, cur_time = tp;
	int tpN = n - 1;
	for(; tpN>=0; tpN--)
	{
		if (tp > 0) cur_time -= t[tpN];
		for(int j=0; j<sz(employer[tpN]); j++)		
		{
			ll nxt = employer[tpN][j];
			if (nxt <= cur_time)
			{
				ma_employer--;
				if (ma_employer <= 0) break;
			} else break;
		}
	}
	return ma_employer <= 0;
}

ll bs(ll l, ll r)
{
	ll ans = 0;
	while (l <= r)
	{
		ll mid = l + (r - l) / 2;
		if (check(mid))
		{
			ans = mid;
			r = mid - 1;
		} else
		{
			l = mid + 1;
		}
	}
	return ans;
}

void solve()
{
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		int K;
		cin >> t[i] >> K;
		for(int j=0; j<K; j++)
		{
			ll x;
			cin >> x;
			employer[i].push_back(x);
		}
		tot += sz(employer[i]);
	}
	
	for(int i=0; i<n; i++)
	{
		sort(employer[i].begin(), employer[i].end());
	}
	
	m = min(m, tot);
	cout << bs(0, 1e18);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("BUS.DAT", "r", stdin);
	freopen("BUS.OUT", "w", stdout);
	solve();
	return 0;
}
