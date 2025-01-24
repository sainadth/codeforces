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

pair<int, int> solve()
{
    int k;
    cin >> k;
    map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        mp[temp]++;
    }
    int n = k - 2;
    for (int i = 1; 2 * i <= n; i++)
    {
        if (n % i == 0)
            if (mp.count(i))
            {
                mp[i]--;
                if (mp.count(n / i))
                    return {i, n / i};
            }
    }
    return {1, 1};
}

int main()
{
    // double t1 = clock();
    // srand(time(0));

    flash;
    int te;
    cin >> te;
    for (int i = 0; i < te; i++)
    {
        auto res = solve();
        cout << res.first << " " << res.second << endl;
    }

    // double t2 = clock();
    // cerr << (t2 - t1) / 1000.0 << endl;

    return 0;
}