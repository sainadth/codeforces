#include <bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multi_ordered_set;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
*/
#define int long long
#define pb push_back
#define flash ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(v) v.begin(), v.end()

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    long long res = 0;
    for (int l = 0; l < min(m / 2, n / 2); l++)
    {
        string s = "";
        int dx = 1;
        int dy = 0;
        int i = l, j = l;
        int k = (n + m - 2 - 4 * l) * 2;
        while (k--)
        {
            s += v[i][j];

            i += dy;
            j += dx;

            if (j == m - l)
            {
                j--;
                dx = 0;
                dy = 1;
                i += dy;
                j += dx;
            }
            if (i == l - 1)
            {
                i++;
                dx = 0;
                dy = -1;
                i += dy;
                j += dx;
            }
            if (j == l - 1)
            {
                j++;
                dx = 0;
                dy = -1;
                i += dy;
                j += dx;
            }
            if (i == n - l)
            {
                i--;
                dx = -1;
                dy = 0;
                i += dy;
                j += dx;
            }
        }
        int sl = s.size();
        for (int i = 0; i < sl; i++)
        {
            if (s[i] == '1' && s[(i + 1) % sl] == '5' && s[(i + 2) % sl] == '4' && s[(i + 3) % sl] == '3')
                res++;
        }
    }
    cout << res << endl;
}

int32_t main()
{
    /* double t1 = clock();
    srand(time(0)); */

    flash;
    int te;
    cin >> te;
    for (int i = 0; i < te; i++)
        solve();

    /* double t2 = clock();
    cout << (t2 - t1) / 1000.0 << endl; */
    return 0;
}