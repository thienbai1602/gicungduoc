#include	<bits/stdc++.h>
#define mod (int)(100)
using namespace std;

typedef long long ll;

int n, m, k, l[105];

void init()
{
	cin >> n >> k;
}

ll poww(int a, int n)
{
	if (n == 1) return a%mod;
	ll t = poww(a, n/2);
	t = (t%mod * t%mod)%mod;
	if (n % 2 == 0) return t%mod; else return (t%mod * a%mod)%mod;
}

void solve()
{
	m = 0;   n = poww(n, k);
	while (l[n] == 0)
	{
		cout << n << " ";
		l[n]++;
		n = poww(n, k);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("LUYTHUA.INP", "r", stdin);
	freopen("LUYTHUA.OUT", "w", stdout);
	init(); solve();
	return 0;
}
