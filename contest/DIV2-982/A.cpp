#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multi_ordered_set;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ll long long
#define pb push_back
#define flash ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(v) v.begin(), v.end()

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &i : v)
    {
        cin >> i.first;
        cin >> i.second;
    }
    sort(all(v), greater<pair<int, int>>());
    int x, y;
    x = v[0].first;
    y = v[0].second;
    ll p = (x + y) << 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i].second > y)
            p += (v[i].second - y) * 2, y = v[i].second;
    }
    cout << p << endl;
}

int main()
{
    flash;
    int te;
    cin >> te;
    for (int i = 0; i < te; i++)
        solve();
    return 0;
}