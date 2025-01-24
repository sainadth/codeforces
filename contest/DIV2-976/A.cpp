#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n, k;
    cin >> n >> k;
    if(k == 1){
        cout << n << endl;
        return;
    }
    int x = ceil(log2(n)/log2(k));
    int c = 0;
    auto t = pow(k, x);
    // cout << "t = " << t << " x = " << x << " p = " << pow(k, x) << endl;
    // while(t < n) t *= k;
    while(n > 0){
        while(t > n){
            t /= k;
        }
        // cout << n << " " << t << endl;
        if(t <= 1){
            c += n;
            n = 0;
        }else{
            n -= t;
            c++;
        }
    }
    cout << c << endl;
}

int main(){
    int te;
    cin >> te;
    for(int i = 0; i < te; i++) solve();
    return 0;
}