#include    <bits/stdc++.h>
#define ll long long
using namespace std;

string S, tutor;
deque<char> pq;

void solve()
{
    cin >> S >> tutor;
    for(char &c : S)
    {
        pq.push_back(c);
    }

    for(char &c : tutor)
    {
        if (c == 'R')
        {
            char x = pq.back();
            pq.pop_back();
            pq.push_front(x);
        } else
        {
            char x = pq.front();
            pq.pop_front();
            pq.push_back(x);
        }
    }

    while(!pq.empty())
    {
        cout << pq.front();
        pq.pop_front();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
