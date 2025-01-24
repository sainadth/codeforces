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
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m));
    vector<int> vis(n + 1, false);
    int ind = 1;
    for (auto &i : v)
    {
        for (auto &j : i)
            cin >> j;
        sort(all(i));
        i.push_back(ind++);
    }
    sort(all(v));
    string res = "";
    int cur = -1;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i][j] < cur)
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                if (!vis[v[i][m]])
                    res += to_string(v[i][m]) + " ";
                vis[v[i][m]] = true;
                cur = v[i][j];
            }
        }
    }
    res.pop_back();
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