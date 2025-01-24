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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int cur = 0;
    int prev = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (prev > 0)
        {
            prev--;
            continue;
        }
        if (s[i] == '0')
        {
            cur++;
            if (cur == m)
            {
                prev = k - 1;
                res++;
                cur = 0;
            }
        }
        else
        {
            cur = 0;
        }
        // cout << cur << " " << prev << endl;
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