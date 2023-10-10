#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e5 + 66;

int n;
int a[mxN];
vector<int> isPrime(3e6 + 66);

void sieve()
{
    for(int i=0; i<=3000000; i++)
    {
        isPrime[i] = i;
    }

    for(int i=2; i*i<=3000000; i++)
    {
        if (isPrime[i] == i)
        {
            for(int j=i*i; j<=3000000; j+=i)
            {
                isPrime[j] = i;
            }
        }
    }
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int ret = 1;
    map<int, int> ma;
    map<int, vector<int>> prime;
    for(int i=0; i<n; i++)
    {
        int X = a[i];
        vector<int> p;
        while(X > 1)
        {
            int pr = isPrime[X];
            while(X % pr == 0) X /= pr;
            p.push_back(pr);
        }

        for(int pr : p)
        {
            int cur_pos = --upper_bound(prime[pr].begin(), prime[pr].end(), a[i]) - prime[pr].begin();
            if (sz(prime[pr]) == cur_pos + 1) prime[pr].push_back(a[i]);
             else prime[pr][cur_pos + 1] = a[i];
            ma[a[i]] = max(ma[a[i]],(cur_pos == -1 ? 1 : ma[prime[pr][cur_pos]] + 1));
            ret = max(ret, ma[a[i]]);
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    sieve(); solve();
    return 0;
}
