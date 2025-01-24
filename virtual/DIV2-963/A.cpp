#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(4, 0);
    for(auto i : s){
        if(i == '?') continue;
        v[i - 'A']++;
    }
    int res = 0;
    for(auto i : v) res += min(n, i);
    cout << res << endl;
}

int main(){
    int te;
    cin >> te;
    for(int i = 0; i < te; i++) solve();
    return 0;
}