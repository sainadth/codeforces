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

int solve()
{
    int a, b;
    cin >> a >> b;
    int l = min(a, b);
    int r = a * b;
    for (int i = l; i <= r; i++)
    {
        if (i % a == i % b)
            return i;
    }
    return -1;
}

int main()
{
    // double t1 = clock();
    // srand(time(0));

    flash;
    int te;
    cin >> te;
    for (int i = 0; i < te; i++)
        cout << solve() << endl;

    // double t2 = clock();
    // cerr << (t2 - t1) / 1000.0 << endl;

    return 0;
}