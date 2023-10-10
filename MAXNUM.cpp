#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
int cnt[15], meta_cnt[15];

void solve()
{
    cin >> N;
    int X = N;
    memset(cnt, 0, sizeof(cnt));
    while(X > 0)
    {
        ++cnt[X % 10];
        X /= 10;
    }

    int ret = 0;
    for(int a=N-1; a>0; a--)
    {
        memset(meta_cnt, 0, sizeof(meta_cnt));
        int tp = a;
        while(tp > 0)
        {
            ++meta_cnt[tp % 10];
            tp /= 10;
        }

        bool flat = true;
        for(int i=0; i<10; i++)
        {
            if (cnt[i] != meta_cnt[i])
            {
                flat = false;
                break;
            }
        }

        if (flat)
        {
            ret = a;
            break;
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("MAXNUM.INP", "r", stdin);
    freopen("MAXNUM.OUT", "w", stdout);
    solve();
    return 0;
}
