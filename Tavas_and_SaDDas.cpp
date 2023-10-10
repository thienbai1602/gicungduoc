#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

ll N;
vector<ll> lucky;

void solve()
{
    cin >> N;
    for(int k=1; k<=10; k++)
    {
        for(ll mask=0; mask<(1 << k); mask++)
        {
            ll num = 0;
            for(int j=0; j<k; j++)
            {
                if (mask & (1 << j))
                {
                    num = num * 10 + 7;
                } else
                {
                    num = num * 10 + 4;
                }
            }
            lucky.push_back(num);
        }
    }

    sort(all(lucky));
    lucky.erase(unique(all(lucky)), lucky.end());
    cout << lower_bound(all(lucky), N) - lucky.begin() + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
