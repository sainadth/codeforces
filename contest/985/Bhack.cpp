#include <bits/stdc++.h>
using namespace std;

int main()
{
    double t1 = clock();
    srand(time(0));

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s, r;
        cin >> s;
        cin >> r;
        int n1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                n1++;
            }
        }
        int n0 = n - n1;
        if (n1 == 0 || n0 == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            bool ok = true;
            for (int i = 0; i < n - 1; i++)
            {
                if (n1 == 0 || n0 == 0)
                {
                    ok = false;
                    break;
                }
                char c = r[i];
                if (c == '1')
                {
                    n0--;
                }
                else
                {
                    n1--;
                }
            }
            if (ok)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    double t2 = clock();
    cout << (t2 - t1) / 1000.0 << endl;
    return 0;
}
