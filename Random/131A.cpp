#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    string s, t;
    cin >> s;
    t = s;
    bool change = true;
    t[0] = toupper(t[0]);
    for (int i = 1; i < s.size(); i++)
    {
        if (islower(s[i]))
        {
            change = false;
            break;
        }
        t[i] = tolower(t[i]);
    }
    if (!change)
    {
        cout << s << endl;
        return 0;
    }
    cout << t << endl;
}