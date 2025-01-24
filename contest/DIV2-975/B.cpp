#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(auto &i : v) cin >> i;
    vector<int> vq(q);
    for(auto &i : vq) cin >> i;
    vector<int> res(n, 0);

    unordered_map<int, int> mp;

    for(int i = 0; i < n/2; i++){
        res[i] = res[n - 1 - i] = ((i + 1) * (n - i)) - 1;
    }

    /* for(auto i : v) cout << i << " ";
    cout << endl;
    for(auto i : vq) cout << i << " ";
    cout << endl;
    for(auto i : res) cout << i << " ";
    cout << endl; */

    int l, r;
    l = 0, r = n - 1;
    while(l < r){
        mp[res[l]] += v[l + 1] - v[l] + 1 + v[r] - v[r - 1] + 1;
        if(r = l + 1) mp[res[l]] /= 2;
        l++;
        r--;
    }

    for(auto i : vq){
        if(mp.count(i)) cout << mp[i];
        else cout << 0;
        cout << " ";
    }
    cout << endl;
}

int main(){
    int te;
    cin >> te;
    for(int i = 0; i < te; i++) solve();
    return 0;
}