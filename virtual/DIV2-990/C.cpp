#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

/* #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multi_ordered_set;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; */

#define ll long long
#define pb push_back
#define flash ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(v) v.begin(), v.end()

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(2, vector<int>(n));
    for (auto &i : v)
        for (auto &j : i)
            cin >> j;
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int cur = v[0][i] + v[1][i];
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            cur += max(v[0][j], v[1][j]);
        }
        res = max(res, cur);
    }
    cout << res << endl;
}

int main()
{
    // double t1 = clock();
    // srand(time(0));

    flash;
    int te;
    cin >> te;
    for (int i = 0; i < te; i++)
        solve();

    // double t2 = clock();
    // cerr << (t2 - t1) / 1000.0 << endl;

    return 0;
}