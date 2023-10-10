#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 3e5 + 55;

int N, pos[mxN], cnt[mxN];
char ans[mxN];
string T;

void solve()
{
    cin >> T;
    N = (int)T.size();

    for(int i=N; i>1; i--)
    {
        int nxt = i - 1, step = i - 1;
        while(nxt + step + 1 <= N)
        {
            nxt += step + 1;
            step = nxt - 1;
        }

        if (nxt < N)
        {
            int dif = N - nxt;
            step = nxt - dif - (nxt != i - 1);
        }
        pos[i] = step + 1;
    }

    for(int i=1; i<N; i++)
    {
        ans[pos[i + 1]] = T[i];
        cnt[pos[i + 1]]++;
    }

    for(int i=1; i<=N; i++)
    {
        if (cnt[i] == 0)
        {
            ans[i] = T[0];
            break;
        }
    }

    for(int i=1; i<=N; i++)
    {
        cout << ans[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
