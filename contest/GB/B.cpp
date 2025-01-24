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
    vector<pair<int, int>> v(n);
    unordered_map<int, int> mp;
    for (auto &i : v)
    {
        cin >> i.first >> i.second;
        if (i.first == i.second)
            mp[i.first]++;
    }
    string res = "";
    for (auto i : v)
    {
        if (i.first == i.second)
        {
            if (mp[i.first] == 1)
                res += '1';
            else
                res += '0';
            continue;
        }

        char cur = '0';
        for (int j = i.first; j <= i.second; j++)
        {
            if (mp.count(j) == 0)
            {
                cur = '1';
                break;
            }
        }
        res += cur;
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