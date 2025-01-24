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
    int l, r;
    cin >> l >> r;
    priority_queue<pair<int, tuple<int, int, int>>> pq;
    for (int i = l; i <= r; i++)
    {
        for (int j = i + 1; j <= r; j++)
        {
            for (int k = j + 1; k <= r; k++)
            {
                pq.push({(i ^ j) + (j ^ k) + (i ^ k), make_tuple(i, j, k)});
            }
        }
    }
    int maxy = pq.top().first;
    while (pq.size())
    {
        auto t = pq.top();
        if (t.first < maxy)
            break;
        cout << t.first << " : {" << get<0>(t.second) << ", " << get<1>(t.second) << ", " << get<2>(t.second) << "}" << endl;
        pq.pop();
    }
    cout << endl;
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