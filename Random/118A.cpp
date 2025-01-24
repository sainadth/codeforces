#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);

    string s;
    cin >> s;
    string res = "";
    for(char i : s){
        char c = tolower(i);
        switch (c)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'y':
                break;
            
            default: res += '.';
                     res += c;
                break;
        }
    }
    cout << res << endl;
}