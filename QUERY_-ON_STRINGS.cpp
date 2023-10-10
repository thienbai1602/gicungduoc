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
    Trie* child[26];
    int cnt;

    Trie()
    {
        cnt = 0;
        for(int c=0; c<26; c++)
        {
            child[c] = NULL;
        }
    }
};


int Q;
Trie* root = new Trie();
map<int, multiset<int>> store;

void add_string(string s)
{
    int pos = 0;
    Trie* p = root;
    for(char c : s)
    {
        if (p -> child[c - 'a'] == NULL) p -> child[c - 'a'] = new Trie();
        p = p -> child[c - 'a'];
        p -> cnt++;
        store[++pos].insert(p -> cnt);
    }
}

bool find_string(string s)
{
    Trie* p = root;
    for(char c : s)
    {
        if (p -> child[c - 'a'] == NULL) return false;
        p = p -> child[c - 'a'];
    }
    return true;
}

void delete_string(string s)
{
    if (!find_string(s)) return;
    int pos = 0;
    Trie* p = root;
    for(char c : s)
    {
        p = p -> child[c - 'a'];
        ++pos;
        store[pos].erase(store[pos].find(p -> cnt));
        p -> cnt--;
    }
}

void solve()
{
    cin >> Q;
    vector<string> S(Q, "");
    for(int i=0; i<Q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            string s;
            cin >> s;
            reverse(all(s));
            S[i] = s;
            add_string(s);
        } else if (type == 2)
        {
            int k, l;
            cin >> k >> l;
            if (store.find(l) != store.end() && store[l].find(k) != store[l].end()) cout << "YES\n";
             else cout << "NO\n";
        } else
        {
            int x;
            cin >> x;
            --x;
            if (S[x] == "") continue;
            delete_string(S[x]);
            S[x] = "";
        }
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
