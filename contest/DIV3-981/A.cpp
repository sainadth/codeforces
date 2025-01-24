#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    cout << ((n & 1) ? "Kosuke" : "Sakurako") << endl;
}

int main()
{
    int te;
    cin >> te;
    for (int i = 0; i < te; i++)
        solve();
    return 0;
}