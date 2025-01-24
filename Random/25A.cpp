#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    vector< pair<int, int> > o, e;
    int j = 0;
    for(int &i : v ){
        cin >> i;
        if(i&1) o.push_back({i, j});
        else e.push_back({i, j});
        j++;
    }
    int res = -1;
    if(o.size() == 1) res = o[0].second;
    else res = e[0].second;
    cout << res + 1 << endl;
}