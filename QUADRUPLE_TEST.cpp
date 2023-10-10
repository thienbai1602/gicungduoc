#include	<bits/stdc++.h>
#define N (int)(4e3+5)
using namespace std;

struct Cur
{
	long val, pos;
}arr[N*N];

int n, m, a[N];
long long res;

void init()
{
	cin >> n;
	n = 4000;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}

	m = 0;
	for(int i=1; i<n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			arr[++m] = {a[i]+a[j], j};
		}
	}
	sort(arr+1, arr+1+m, [](Cur &ax, Cur &ay) {return ax.val<ay.val;});
}

long cnt(long ax, int k)
{
	long ret = 0;   int ans = -1;
	int l = 1, r = m;
	while (l<=r)
	{
		int mid = l+(r-l)/2;
		if (arr[mid].val>=ax)
		{
			if (arr[mid].val==ax) ans = mid;
			r = mid-1;
		} else
		{
			l = mid+1;
		}
	}

	if (ans != -1)
	{
		for(int i=ans; i<=m; i++)
		{
			if (arr[i].val>ax) break;
			if (arr[i].pos<k) ret++;
		}
	}
	return ret;
}

void solve()
{
	res = 0;
	for(int i=1; i<n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			res += cnt(a[i]+a[j], i);
		}
	}
	cout << res;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    freopen("CINDEX.INP", "r", stdin);
	freopen("CINDEX.OUT", "w", stdout);
	init(); solve();
	return 0;
}
