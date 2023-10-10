#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int base = 311;
const int mxN = 5066;
const ll mod[2] = {(ll)1e9 + 3, (ll)1e9 + 7};

string S;
int N, cnt[305];
ll hsh[mxN][2], pw[mxN][2];

bool check(ll A, ll B, int st, int ed)
{
    ll sub1 = (hsh[ed][0] - hsh[st - 1][0] * pw[ed - st + 1][0] + mod[0] * mod[0]) % mod[0];
    ll sub2 = (hsh[ed][1] - hsh[st - 1][1] * pw[ed - st + 1][1] + mod[1] * mod[1]) % mod[1];
    return (A == sub1 && B == sub2);
}

void solve()
{
    cin >> S;
    N = sz(S);

    pw[0][0] = pw[0][1] = 1;
    for(int i=0; i<N; i++)
    {
        for(int ps=0; ps<2; ps++)
        {
            pw[i + 1][ps] = (pw[i][ps] * base) % mod[ps];
        }
    }

    hsh[0][0] = hsh[0][1] = 0;
    for(int i=0; i<N; i++)
    {
        for(int ps=0; ps<2; ps++)
        {
            hsh[i + 1][ps] = (hsh[i][ps] * base + S[i]) % mod[ps];
        }
    }

    int cur_sz = N ;
    ll sub_hash1 = 0, sub_hash2 = 0;
    for(int i=1; i<=N; i++)
    {
        sub_hash1 = (sub_hash1 * base + S[i - 1]) % mod[0];
        sub_hash2 = (sub_hash2 * base + S[i - 1]) % mod[1];

        bool flat = false;
        if (N % i == 0)
        {
            for(int j=i; j<N; j+=i)
            {
                if (!check(sub_hash1, sub_hash2, j + 1, j + i)) break;
                flat = (j == N - i);
            }
        }

        if (flat)
        {
            cur_sz = i;
            break;
        }
    }

    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<cur_sz; i++)
    {
        ++cnt[S[i]];
    }

    int ret = 0;
    for(int i=0; i<305; i++)
    {
        ret = max(ret, cnt[i]);
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
