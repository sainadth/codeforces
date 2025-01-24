#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n), pi(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
        pi[p[i]] = i;
    }

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (p[i] == i || p[p[i]] == i)
            continue;
        else
        {
            int loc = pi[i];
            int temp = p[p[i]];
            swap(p[p[i]], p[pi[i]]);
            pi[i] = p[p[i]];
            pi[temp] = loc;
            res++;
        }
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