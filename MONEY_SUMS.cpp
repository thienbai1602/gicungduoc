#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int n;
bitset<mxN> can;

void solve()
{
    cin >> n;
    can[0] = 1;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        can |= (can << x);
    }

    vector<int> res;
    for(int i=1; i<mxN; i++)
    {
        if (can[i])
        {
            res.push_back(i);
        }
    }

    cout << (int)res.size() << "\n";
    for(int& x : res) cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
