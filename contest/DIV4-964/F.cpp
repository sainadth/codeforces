#include<bits/stdc++.h>
using namespace std;

vector<int> factorial;
vector<int> inverse_factorial;
int MAXN = 2e5 + 1;
int MOD = 1e9 + 7;

long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse_factorial[k] % MOD * inverse_factorial[n - k] % MOD;
}

void solve(){
    int MOD = 1e9 + 7;
    int res = 0;
    cout << res << endl;
}

int main(){
    int te;
    cin >> te;
    factorial.resize(MAXN + 1, 0);
    inverse_factorial.resize(MAXN + 1, 0);
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
    for(int i = 0; i < te; i++) solve();
    return 0;
}