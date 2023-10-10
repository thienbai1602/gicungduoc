#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 55;

int n;
ll L, R, a[mxN];

void solve()
{
    cin >> n >> L >> R;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    if (n == 1)
    {
        ll mid = (L + R) >> 1;
        if (mid < a[0]) cout << L;
         else cout << R;
        return;
    }

    ll ret = -1, pos = -1;
    if (L <= a[0])
    {
        if (ret <= a[0] - L)
        {
            ret = a[0] - L;
            pos = L;
        }
    }

    if (R >= a[n - 1])
    {
        if (ret <= R - a[n - 1])
        {
            ret = R - a[n - 1];
            pos = R;
        }
    }

    for(int i=0; i<n-1; i++)
    {
        ll mid = (a[i + 1] + a[i]) / 2;
        if (mid >= L && mid <= R)
        {
            ll nxt = min(mid - a[i], a[i + 1] - mid);
            if (ret <= nxt)
            {
                pos = (ret == nxt ? max(pos, mid) : pos);
                ret = nxt;
                //cout << ret << " " << pos << "\n";
            }
        } else
        {
            if (L >= a[i] && R <= a[i + 1])
            {
                ll nxt = (R < mid ? R - a[i] : a[i + 1] - L);
                if (ret <= nxt)
                {
                    pos = (ret == nxt ? max(pos, (R < mid ? R : L)) : pos);
                    ret = nxt;
                    //cout << ret << " " << pos << "\n";
                }
            }

            if (i > 0 && a[i] >= L && a[i] <= R)
            {
                if (L >= a[i - 1] && R <= a[i + 1])
                {
                    ll nxt = min(L - a[i - 1], a[i] - L);
                    nxt = max(nxt, min(R - a[i], a[i + 1] - R));
                    if (ret <= nxt)
                    {
                        pos = (ret == nxt ? max(pos, ((nxt == R - a[i]) || (nxt == a[i + 1] - R) ? R : L)) : pos);
                        ret = nxt;
                        //cout << ret << " " << pos << "\n";
                    }
                }
            }
        }
    }
    cout << pos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
