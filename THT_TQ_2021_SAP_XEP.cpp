#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

vector<string> store;
int ret = 0;
ll a, b;

string trade(ll X)
{
    string ans;
    vector<int> num;
    while(X > 0)
    {
        int tp = X % 10;
        ans = (char)(tp + '0') + ans;
        X /= 10;
    }
    return ans;
}

bool cmp(string a, string b)
{
    for(int i=0; i<min(sz(a), sz(b)); i++)
    {
        if (a[i] < b[i]) return false;
        if (a[i] > b[i]) return true;
    }
    return sz(a) > sz(b);
}

int bs(int l, int r, string s)
{
    int ans = 0;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if (cmp(s, store[m - 1]))
        {
            ans = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> a >> b;
    store.resize(b - a + 2);
    ret = 1, store[0] = trade(a);
    for(ll cur=a+1; cur<=b; cur++)
    {
        string nxt = trade(cur);
        int pos = bs(1, ret, nxt);
        //cout << nxt << " " << store[pos] << " " << pos << " " <<  cmp(nxt, store[pos]) << "\n";
        ret = max(ret, pos + 1);
        store[pos] = nxt;
    }
    cout << (b - a + 1) - ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
