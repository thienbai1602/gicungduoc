#include	<bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

ll X, K, dp[55][55][2][2];

ll recur(vector<int>& num, int N, int cntK, bool leading, bool tight)
{
	if (cntK > K) return 0;
	if (N == 0)
	{
		return (cntK == K && !leading);
	}

	if (dp[N][cntK][leading][tight] != -1) return dp[N][cntK][leading][tight];

	ll ans = 0;
	int limit = tight ? num[sz(num) - N] : 1;
	for(int digit=0; digit<=limit; digit++)
	{
		ans += recur(num, N - 1, (leading && digit == 0 ? 0 : cntK + (digit == 0)), leading && (digit == 0), tight && (digit == limit));
	}
	return dp[N][cntK][leading][tight] = ans;
}

ll sol(ll X)
{
    vector<int> num;
	while(X > 0)
	{
		num.push_back(X % 2);
		X /= 2;
	}
	reverse(num.begin(), num.end());
	memset(dp, -1, sizeof(dp));
	return recur(num, sz(num), 0, 1, 1);
}

void solve()
{
	cout << sol(X) + (K == 1) << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("NUMBER.INP", "r", stdin);
	//freopen("NUMBER.OUT", "w", stdout);
	while(cin >> X >> K) solve();
	return 0;
}
