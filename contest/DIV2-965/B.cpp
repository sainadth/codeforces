#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int &i : v) cin >> i;
    int k = v[0];
    for(int i = 0; i < n - 1; i++){
        v[i] = v[i + 1];
    }
    v.back() = k;
    for(int i : v) cout << i << " ";
    cout << endl;
}

int main(){
    int te;
    cin >> te;
    for(int i = 0; i < te; i++) solve();
    return 0;
}