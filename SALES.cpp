#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int n, wrong = 0;
map<int, int> cnt;

void solve()
{
    cin >> n;
    vector<int> compressed;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        compressed.push_back(x);
        cnt[x]++;
    }

    sort(compressed.begin(), compressed.end());
    compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());

    ll ret = 0;
    bool wrong = true;
    for(int i=0; i<(int)compressed.size(); i++)
    {
        if (cnt[compressed[i]] < 2)
        {
            wrong = false;
            break;
        }

        ll x = cnt[compressed[i]];
        for(int i=0; i<3; i++)
        {
            if ((x - i * 2) % 3 == 0)
            {
                ret += i + (x - i * 2) / 3;
                break;
            }
        }
    }
    cout << (!wrong ? -1 : ret);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
