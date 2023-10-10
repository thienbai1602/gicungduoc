#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 2e5 + 66;

struct Data
{
    ll a, b, id;
}seg[mxN];

int n;
ll x, y;

bool cmp(Data z, Data t)
{
    return z.a < t.a;
}

void solve()
{
    cin >> n >> x >> y;
    for(int i=0; i<n; i++)
    {
        cin >> seg[i].a >> seg[i].b;
        seg[i].id = i + 1;
    }

    sort(seg, seg + n, cmp);

    int j = 0;
    vector<int> res;
    bool check = false;
    ll yMax = seg[0].a, idxMax = seg[0].id;
    while(!check)
    {
        bool check2 = false;
        int ps = upper_bound(seg + j, seg + n, Data{x}, cmp) - seg;
        for(int i=j; i<ps; i++)
        {
            if (seg[i].id != 0)
            {
                check2 = true;
                if (yMax < seg[i].b)
                {
                    yMax = seg[i].b;
                    idxMax = seg[i].id;
                }
                seg[i].id = 0;
            }
        }

        if (!check2) break;
        res.push_back(idxMax);
        x = yMax, j = ps;
        if (x  >= y)
        {
            check = true;
            break;
        }
    }

    if (!check)
    {
        cout << -1;
    } else
    {
        cout << (int)res.size() << "\n";
        for(int i=0; i<(int)res.size(); i++)
        {
            cout << res[i] << " ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
