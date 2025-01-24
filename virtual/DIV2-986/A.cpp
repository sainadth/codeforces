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
#define yes "YES"
#define no "NO"

void solve()
{
    /* fast and slow pointer */
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    pair<int, int> fast = {0, 0}, slow = {0, 0};
    int dpx[4] = {0, 1, 0, -1};
    int dpy[4] = {1, 0, -1, 0};
    map<char, int> dir;
    dir['N'] = 0;
    dir['E'] = 1;
    dir['W'] = 2;
    dir['S'] = 3;

    bool canTravel = true;
    int si = 0, fi = 0;
    while (true)
    {
        slow.first += dpx[dir[s[si]]];
        slow.second += dpy[dir[s[si]]];
        si++;
        si %= n;

        if (slow.first == a && slow.second == b)
            break;

        if (slow.first > 1000 || slow.second > 1000)
        {
            canTravel = false;
            break;
        }
    }
    cout << (canTravel ? yes : no) << endl;
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
    cout << (t2 - t1) / 1000.0 << endl;

    return 0;
}