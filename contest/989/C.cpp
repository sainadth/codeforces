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

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void traverse(int i, int j, int m, int n, vector<pair<int, int> > &path, vector<vector<int> > &dp, vector<vector<char> > &v)
{
    if (i < 0 || j < 0 || i >= m || j >= n || dp[i][j] == 1)
    {
        for (auto i : path)
        {
            dp[i.first][i.second] = 1;
        }
        return;
    }
    if (dp[i][j] == 0)
    {
        for (auto i : path)
        {
            dp[i.first][i.second] = 0;
        }
        return;
    }
    if (v[i][j] == 'U')
    {
        path.push_back(make_pair(i - 1, j));
        traverse(i - 1, j, m, n, path, dp, v);
    }
    else if (v[i][j] == 'R')
    {
        path.push_back(make_pair(i, j + 1));
        traverse(i, j + 1, m, n, path, dp, v);
    }
    else if (v[i][j] == 'D')
    {
        path.push_back(make_pair(i + 1, j));
        traverse(i + 1, j, m, n, path, dp, v);
    }
    else if (v[i][j] == 'L')
    {
        path.push_back(make_pair(i, j - 1));
        traverse(i, j - 1, m, n, path, dp, v);
    }
}

void solve()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char> > v(m, vector<char>(n));
    vector<vector<int> > dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
            if (i == 0)
            {
                if (v[i][j] == 'U')
                    dp[i][j] = 1;
            }
            if (j == 0)
            {
                if (v[i][j] == 'L')
                    dp[i][j] = 1;
            }
            if (i == m - 1)
            {
                if (v[i][j] == 'D')
                    dp[i][j] = 1;
            }
            if (j == n - 1)
            {
                if (v[i][j] == 'R')
                    dp[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == -1 && v[i][j] != '?')
            {
                vector<pair<int, int> > path;
                path.push_back(make_pair(i, j));
                traverse(i, j, m, n, path, dp, v);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == -1 && v[i][j] != '?')
            {
                for (int k = 0; k < 4; k++)
                {
                    int it = i + dx[k];
                    int jt = j + dy[k];
                    if (it >= 0 && it < m && jt >= 0 && jt < n)
                    {
                        if (v[it][jt] == '?' || dp[it][jt] == 0 || dp[i][j] == 0)
                        {
                            dp[i][j] = 0;
                            dp[it][jt] = 0;
                        }
                    }
                }
            }
        }
    }

    long long res = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
            if (dp[i][j] == 0)
                res++;
        }
        cout << endl;
    }
    cout << res << endl;
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