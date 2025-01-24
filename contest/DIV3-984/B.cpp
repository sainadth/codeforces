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
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> mp;
    while (k--)
    {
        int b, c;
        cin >> b >> c;
        if (mp.count(b))
            mp[b] += c;
        else
            mp[b] = c;
    }

    priority_queue<pair<int, int>> pq;
    for (auto i : mp)
    {
        pq.push({i.second, i.first});
    }
    long long res = 0;
    while (n--)
    {
        res += pq.top().first;
        pq.pop();
        if (pq.size() == 0)
            break;
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