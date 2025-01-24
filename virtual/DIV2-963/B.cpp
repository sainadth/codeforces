#include<bits/stdc++.h>
using namespace std;

void solve(){
    /* Making even to odd if there is atleast one odd number */
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> even; 
    long long maxOdd = 0;

    for(auto &i : v){
        cin >> i;
        if(i&1) maxOdd = max(maxOdd, i * 1LL);
        else even.push_back(i);
    }

    int res = 0;
    sort(even.begin(), even.end(), [](int a, int b){
        return a < b;
    });

    if(maxOdd != 0 && even.size()){
        res = even.size();
        int cur = 0;
        int i = 0;
        while(i < even.size()){
            if(even[i] > maxOdd){
                res = even.size() + 1;
                break;
            }else{
                maxOdd += even[i];
                cur++;
            }
            i++;
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