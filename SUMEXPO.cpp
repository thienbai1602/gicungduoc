#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e4 + 66;

ll N;

void solve()
{
    cin >> N;
    ll even = 0, odd = 0, pr = 2;
    while(pr * pr <= N)
    {
        int ct = 0;
        while(N % pr == 0)
        {
            N /= pr;
            ++ct;
        }
        ++pr;
        if (ct & 1) odd += ct;
         else even += ct;
    }

    if (N > 1) odd++;
    cout << even << "\n" << odd;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
