#include<bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> a(2, 0), x(2, 0);
    cin >> a[0] >> a[1] >> x[0] >> x[1];
    int res = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            int s = 0;
            if(a[j] > x[i]) s++;
            else if(a[j] < x[i]) s--;
            if(a[!j] > x[!i]) s++;
            else if(a[!j] < x[!i]) s--;
            if(s > 0) res++;
        }
    }
    cout << res << endl;
}

int main(){
    int te;
    cin >> te;
    for(int i = 0; i < te; i++) solve();
    return 0;
}