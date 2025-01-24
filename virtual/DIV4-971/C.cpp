#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x, y, k;
    cin >> x >> y >> k;
    x = ceil(x/(1.0 * k));
    y = ceil(y/(1.0 * k));
    int res = max(x, y) * 2;
    if(x > y) res--;
    cout << res << endl;
}

int main(){
    int te;
    cin >> te;
    for(int i = 0; i < te; i++) solve();
    return 0;
}