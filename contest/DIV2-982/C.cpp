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

map<ll, ll> mem;
map<ll, vector<ll>> mp;
ll traverse(ll n)
{
    if (mem.find(n) != mem.end())
        return mem[n];
    ll res = n;
    for (ll i : mp[n])
    {
        res = max(res, traverse(n + i));
    }
    return mem[n] = res;
}
void solve()
{
    mem.clear();
    mp.clear();
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll t = 0;
    for (auto &i : v)
    {
        cin >> i;
        if (t)
            mp[i + t].push_back(t);
        t++;
    }
    cout << traverse(n) << endl;
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