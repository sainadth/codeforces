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
    vector<int> v(1001);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v[temp]++;
    }

    vector<pair<int, int>> uv;

    for (int i = 0; i < 1001; i++)
    {
        if (v[i])
            uv.push_back({v[i], i});
    }

    sort(all(uv));

    int k = (n + 1) / 2;
    int i = 0;

    while (k)
    {
        if (uv[i].first)
        {
            uv[i].first--;
            k--;
        }
        i++;
        i %= uv.size();
    }
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