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

bool isPrime(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    if (n < 5)
    {
        cout << -1 << endl;
        return;
    }
    int last_odd = 1;
    for (int i = 1; i <= n; i += 2)
    {
        cout << i << " ";
        last_odd = i;
    }
    int k = last_odd - 1;
    while (isPrime(last_odd + k))
    {
        k -= 2;
    }
    cout << k << " ";
    int i = 2;
    while (i <= n)
    {
        if (i != k)
            cout << i << " ";
        i += 2;
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