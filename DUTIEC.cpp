#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 25;

int n, ed;
int p[mxN];
string S[mxN];
bool flat = false;
vector<int> edges[mxN];

void dfs(int u, int deep)
{
    if (deep == n - 1)
    {
        for(int v : edges[u])
        {
            if (v == 0)
            {
                ed = u;
                flat = true;
                break;
            }
        }
        return;
    }

    for(int v : edges[u])
    {
        if (p[v] == -1)
        {
            p[v] = u;
            dfs(v, deep + 1);
            if (flat) return;
            p[v] = -1;
        }
    }
}

void tv(int u)
{
    vector<int> path;
    while(u != n + 1)
    {
        path.pb(u);
        u = p[u];
    }

    for(int i=sz(path)-1; i>=0; i--)
    {
        cout << path[i] + 1 << "\n";
    }
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> S[i];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if (i == j) continue;
            bool check = false;
            for(char a : S[i])
            {
                for(char b : S[j])
                {
                    if (a == b)
                    {
                        check = true;
                        edges[i].pb(j);
                        break;
                    }
                }
                if (check) break;
            }
        }
    }

    fill(p, p + n, -1);
    p[0] = n + 1;
    dfs(0, 0);
    if (flat) tv(ed);
     else cout << "NO SOLUTION";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
