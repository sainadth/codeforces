#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);


    int n;
    cin >> n;
    int x = 0, y = 0, z = 0;
    while(n--){
        int a, b, c;
        cin >> a >> b >> c;
        x += a;
        y += b;
        z += c;
    }
    cout << ((x == y && y == z && z == 0) ? "YES" : "NO") << endl;
}