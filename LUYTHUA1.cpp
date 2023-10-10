#include	<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

ll a, b;

ll lt(ll n)
{
	if (n == 1) return a%10;
	ll t = lt(n/2);
	t = (t%10*t%10)%10;
	if (n&1) return (t%10*a%10); else return t%10;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> a >> b;
	cout << lt(mod - 1); //cout << lt(b);
	return 0;
}
