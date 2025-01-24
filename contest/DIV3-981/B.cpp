#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (auto &i : v)
        for (auto &j : i)
            cin >> j;
    int res = 0;
    for (int d = 1 - n; d < n; d++)
    {
        int mn = 0;
        for (int j = abs(min(0, d)); max(j, j + d) < n; j++)
        {
            mn = min(mn, v[j][j + d]);
        }
        res -= mn;
    }
    cout << res << endl;
}

int main()
{
    int te;
    cin >> te;
    for (int i = 0; i < te; i++)
        solve();
    return 0;
}