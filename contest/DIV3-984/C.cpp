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
    string s;
    cin >> s;
    int n = s.size();
    unordered_map<int, int> mp;
    int res = 0;
    for (int i = 0; i < n - 3; i++)
    {
        if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
        {
            mp[i]++;
            res++;
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int i, c;
        cin >> i >> c;
        s[i - 1] = c + '0';
        for (int j = max(0, i - 4); j < i; j++)
        {
            if (j + 3 >= n)
                break;
            if (s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0')
            {
                if (mp.count(j) == 0)
                {
                    mp[j]++;
                    res++;
                }
            }
            else
            {
                if (mp.count(j))
                {
                    mp.erase(j);
                    res--;
                }
            }
        }
        cout << (res ? "YES" : "NO") << endl;
    }
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