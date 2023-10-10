#include    <bits/stdc++.h>
#define ll long long
using namespace std;

pair<ll, ll> Bessie, farmer, overlap;

int main()
{
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    cin >> farmer.first >> farmer.second >> Bessie.first >> Bessie.second;
    overlap = make_pair(max(farmer.first, Bessie.first), min(farmer.second, Bessie.second));
    cout << (farmer.second - farmer .first) + (Bessie.second - Bessie.first) - (overlap.second > overlap.first ? overlap.second - overlap.first : 0);
    return 0;
}
