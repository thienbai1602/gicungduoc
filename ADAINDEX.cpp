#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

struct Trie
{
    struct Node
    {
        int child[26];
        int exist, cnt;
    } node[mxN];

    int cur;
    Trie() : cur(0){
        memset(node[0].child, -1, sizeof(node[0].child));
        node[0].exist = node[0].cnt = 0;
    };

    int new_node()
    {
        ++cur;
        memset(node[cur].child, -1, sizeof(node[cur].child));
        node[cur].exist = node[cur].cnt = 0;
        return cur;
    }

    void add_string(string s)
    {
        int pos = 0;
        for(char c : s)
        {
            if (node[pos].child[c - 'a'] == -1)
            {
                node[pos].child[c - 'a'] = new_node();
            }
            pos = node[pos].child[c - 'a'];
            node[pos].cnt++;
        }
        node[pos].exist++;
    }

    bool delete_string_recur(int pos, string& s, int i)
    {
        if (i != sz(s))
        {
            int c = s[i] - 'a';
            bool is_child = delete_string_recur(node[pos].child[c], s, i + 1);
            if (is_child) node[pos].child[c] = -1;
        } else node[pos].exist--;

        if (pos != 0)
        {
            node[pos].cnt--;
            if (node[pos].cnt == 0) return true;
        }
        return false;
    }

    void delete_string(string s)
    {
        if (find_string(s) == false) return;
        delete_string_recur(0, s, 0);
    }

    bool find_string(string s)
    {
        int pos = 0;
        for(char f : s)
        {
            int c = f - 'a';
            if (node[pos].child[c] == -1) return false;
            pos = node[pos].child[c];
        }
        return (node[pos].exist != 0);
    }

    ll query(int pos, int i, string& s)
    {
        if (i == sz(s)) return node[pos].cnt;
        if (node[pos].child[s[i] - 'a'] == -1) return 0;
         else return query(node[pos].child[s[i] - 'a'], i + 1, s);
    }
}trie;

int N, Q;

void solve()
{
    cin >> N >> Q;
    for(int i=0; i<N; i++)
    {
        string S;
        cin >> S;
        trie.add_string(S);
    }

    for(int i=0; i<Q; i++)
    {
        string S;
        cin >> S;
        cout << trie.query(0, 0, S) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}

