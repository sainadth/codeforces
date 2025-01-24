#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s, t;
    cin >> s >> t;
    int j = 0;
    bool res = false;
    for(int i = 0; i < s.size(); i++){
        if(j == t.size() && s[i] == '?'){
            s[i] = 'a';
        }
        if(s[i] == '?'){
            s[i] = t[j];
            j++;
        }
        else if(s[i] == t[j]){
            j++;
        }
    }
    if(j == t.size()) res = true;
    if(res) cout << "YES\n" << s << endl;
    else cout << "NO" << endl;
}

int main(){
    int te;
    cin >> te;
    for(int i = 0; i < te; i++) solve();
    return 0;
}