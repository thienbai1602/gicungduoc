#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int tc;
ll a, b, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    for(int i=0; i<tc; i++)
    {
        cin >> a >> b >> c;
        cout << "Case " << i + 1 << ": ";
        cout << (c % __gcd(a, b) == 0 ? "Yes" : "No") << "\n";
    }
    return 0;
}
