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
    ll n;
    cin >> n;
    string s, r;
    cin >> s >> r;

    ll a = 0, b = 0;
    for (auto i : s)
        (i == '0') ? a++ : b++;

    for (auto i : r)
    {
        if (a == 0 || b == 0)
            break;
        (i == '0') ? b-- : a--;
    }
    cout << (a + b == 1 ? "YES" : "NO") << endl;
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