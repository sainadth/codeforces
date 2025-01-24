#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    for (int i = 1; i < n / 2; i++)
    {
        if (v[i] == v[i - 1] or v[n - 1 - i] == v[n - i])
        {
            swap(v[i], v[n - 1 - i]);
        }
    }
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        res += (v[i] == v[i + 1]);
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