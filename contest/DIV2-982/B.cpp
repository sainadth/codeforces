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
    vector<ll> v(n, 0);
    for (auto &i : v)
        cin >> i;
    int res = INT_MAX;
    int curMax = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] >= curMax)
        {
            curMax = v[i];
            res = i;
        }
        /* else
        {
            res = min(res, res + 1 + (v[i] == v[i + 1]));
        } */
    }
    cout << res << endl;
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