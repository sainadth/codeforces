#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<long long, int> mp;
    long long s = 0;
    int cur = -1;
    int res = 0;
    mp[0] = -1;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        s += temp;
        if (mp.count(s))
        {
            if (cur <= mp[s])
            {
                res++;
                cur = i;
            }
        }
        mp[s] = i;
    }
    cout << res << endl;
}

int main()
{
    int te;
    cin >> te;
    for (int i = 0; i < te; i++)
        solve();
    return 0;
}