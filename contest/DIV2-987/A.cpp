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
    vector<pair<int, int> > h;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (h.size() == 0 || h.back().first != temp)
            h.push_back(make_pair(temp, 1));
        else
            h.back().second++;
    }
    int res = INT_MAX;
    for (int i = 0; i < h.size(); i++)
    {
        res = min(res, n - h[i].second);
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
    // cout << (t2 - t1) / 1000.0 << endl;

    return 0;
}