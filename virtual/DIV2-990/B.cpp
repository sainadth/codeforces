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
    string s;
    cin >> n >> s;
    vector<int> v(26, 0);
    char curmax;
    char curmin;
    for (auto i : s)
        v[i - 'a']++;
    vector<pair<int, char>> vp;

    for (int i = 0; i < 26; i++)
        if (v[i])
            vp.push_back({v[i], 'a' + i});

    sort(all(vp));
    if (vp.size() > 1)
    {
        curmin = vp[0].second;
        curmax = vp.back().second;
        for (auto &i : s)
        {
            if (i == curmin)
            {
                i = curmax;
                break;
            }
        }
    }

    cout << s << endl;
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