#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    int maxy = 0;
    int total = 0;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        mp[temp]++;
        total++;
        maxy = max(maxy, mp[temp]);
    }
        
}

int main(){
    int te;
    cin >> te;
    for(int i = 0; i < te; i++) solve();
    return 0;
}