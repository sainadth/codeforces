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
    if (n & 1)
    {
        if (n < 27)
        {
            cout << "-1" << endl;
            return;
        }
        cout << "1 "; // 1 at 0
        for (int i = 2; i <= 5; i++)
            cout << i << " " << i << " ";
        cout << "1 "; // 1 at 9
        for (int i = 6; i < 13; i++)
            cout << i << " " << i << " ";
        cout << "13 1 13 ";
        for (int i = 0; i < (n - 27) / 2; i++)
        {
            cout << i + 14 << " " << i + 14 << " ";
        }
    }
    else
    {
        int i = 1;
        n >>= 1;
        while (n--)
        {
            cout << i << " " << i << " ";
            i++;
        }
    }
    cout << endl;
}

int main()
{
    double t1 = clock();
    srand(time(0));

    flash;
    int te;
    cin >> te;
    for (int i = 0; i < te; i++)
        solve();

    double t2 = clock();
    cerr << (t2 - t1) / 1000.0 << endl;
    return 0;
}

// 1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 12 12 13 1 13 14 14 15 15 16 16 17 17 18 18 19 19 20 20 21 21 22 22 23 23