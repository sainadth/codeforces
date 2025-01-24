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
    vector<int> even, odd;
    long long s = 0;
    long long res = 0;
    for (auto &i : v)
    {
        cin >> i;
        if (i & 1)
            odd.pb(i);
        else
            even.pb(i);
    }
    int i = 0, j = 0;
    while (i < even.size() && j < odd.size())
    {
        if (s & 1)
            s += odd[j++];
        else
            s += even[i++];
        if (s % 2 == 0)
            res++;
        while (s % 2 == 0)
        {
            s >>= 1;
        }
    }

    while (i < even.size())
    {
        s += even[i++];
        if (s % 2 == 0)
            res++;
        while (s % 2 == 0)
        {
            s >>= 1;
        }
    }

    while (j < odd.size())
    {
        s += odd[j++];
        if (s % 2 == 0)
            res++;
        while (s % 2 == 0)
        {
            s >>= 1;
        }
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
