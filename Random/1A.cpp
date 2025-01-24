#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n, m, a;
    cin >> n >> m >> a;
    __int64 res = ceil(n/(1.0 * a)) * ceil(m/(1.0 * a));
    cout << res << endl;
}