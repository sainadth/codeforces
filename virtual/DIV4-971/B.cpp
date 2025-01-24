#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> res;
    while(n--){
        string s;
        cin >> s;
        for(int i = 0; i < 4; i++)
            if(s[i] == '#'){
                res.push_back(i + 1);
                break;
            }
    }
    while(res.size()){
        cout << res.back() << " ";
        res.pop_back();
    }
    cout << endl;
}

int main(){
    int te;
    cin >> te;
    for(int i = 0; i < te; i++) solve();
    return 0;
}