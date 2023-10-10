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
const int mxN = 5e5 + 66;

struct Trie
{
    Trie* child[26];
    int cnt, exist, mx_exist;

    Trie()
    {
        cnt = mx_exist = exist = 0;
        set0(child);
    }
};

Trie* root = new Trie();
void add_string(string s)
{
    Trie* p = root;
    for(char c : s)
    {
        if (p -> child[c - 'a'] == NULL) p -> child[c - 'a'] = new Trie();
        p = p -> child[c - 'a'];
        p -> cnt++;
    }
    p -> exist++;

    Trie* now = root;
    int res_cnt = p -> exist;
    for(char c : s)
    {
        now -> mx_exist = max(now -> mx_exist, res_cnt);
        now = now -> child[c - 'a'];
    }
    now -> mx_exist = max(now -> mx_exist, res_cnt);
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

void output_ans(string& ans)
{
    Trie* now = root;
    for(char c : ans)
    {
        now = now -> child[c - 'a'];
        cout << c;
    }

    int res = now -> mx_exist;
    while(now -> exist != now -> mx_exist)
    {
        for(int c=0; c<26; c++)
        {
            if (now -> child[c] != NULL && now -> child[c] -> mx_exist == res)
            {
                cout << (char)('a' + c);
                now = now -> child[c];
                break;
            }
        }
    }
    cout << " " << res << "\n";
}

int N, Q;

void solve()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        string S;
        cin >> S;
        add_string(S);
    }

    cin >> Q;
    while(Q--)
    {
        string S;
        cin >> S;
        bool flat = find_string(S);
        if (!flat) cout << "-1\n";
         else output_ans(S);
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
