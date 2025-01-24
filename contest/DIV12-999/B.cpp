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
    vector<int> v(n);
    map<int, int> mp;
    set<int> twos;
    string res = "";
    for (int &i : v)
    {
        cin >> i;
        mp[i]++;
        if (mp[i] > 3)
        {
            res += to_string(i) + " ";
            cout << res << endl;
            return;
        }
        if (mp[i] > 1)
        {
            twos.insert(i);
        }
    }

    if (twos.size() == 0)
    {
        cout << -1 << endl;
        return;
    }
    if (twos.size() > 1)
    {
        res += to_string(*twos.begin()) + " " + to_string(*twos.begin()) + " " + to_string(*twos.rbegin()) + " " + to_string(*twos.rbegin());
        cout << res << endl;
        return;
    }
    vector<pair<int, int> > vp;
    for (auto i : mp)
    {
        vp.push_back({i.second, i.first});
    }
    sort(all(vp));
    for (int i = 0; i < vp.size(); i++)
    {
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