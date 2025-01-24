#include<bits/stdc++.h>
using namespace std;

vector<int> pref;

void solve(){
    int l, r;
    cin >> l >> r;
    int res = 0;
    res += pref[r] - pref[l];
    res += 2 * (pref[l] - pref[l - 1]); 
    cout << res << endl;
}

int main(){
    int te;
    cin >> te;
    int cnt = 0;
    pref.resize(2e5 + 1, 0);
    int c = 1;
    for(int i = 1; i < 2e5 + 1; i++){
        if(i == c){
            c *= 3;
            cnt++;
        }
        pref[i] = cnt + pref[i - 1];
    }
    for(int i = 0; i < te; i++) solve();
    return 0;
}