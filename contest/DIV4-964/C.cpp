#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, s, m;
    cin >> n >> s >> m;
    vector<pair<int, int>> v(n);
    for(auto &i : v) cin >> i.first >> i.second;
    pair<int, int> prev = {-1, 0};
    bool res = false;
    for(auto i : v){
        if(i.first - prev.second >= s){
            res = true;
            break;
        }
        prev = i;
    }
    if(m - v.back().second >= s) res = true;
    cout << ((res) ? "YES" : "NO") << endl;
}

int main(){
    int te;
    cin >> te;
    for(int i = 0; i < te; i++) solve();
    return 0;
}