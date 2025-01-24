#include<bits/stdc++.h>
using namespace std;
class DSU{
    vector<int> parent;
public:
    DSU(int n){
        parent.resize(n);
        int j = 0;
        for(auto &i : parent) i = j++;
    }

    int Find(int x){
        if(parent[x] == x) return x;
        return Find(parent[x]);
    }

    bool Union(int x, int y){
        int parent_x = Find(x);
        int parent_y = Find(y);
        if(parent_x != parent_y){
            if(parent_x <= parent_y) parent[parent_y] = parent_x;
            else parent[parent_x] = parent_y;
            return true;
        }
        return false;
    }
};
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n, m;
    cin >> n >> m;
    DSU* dsu = new DSU(n + 1);
    while(m--){
        string op;
        int x, y;
        cin >> op >> x >> y;
        if(op == "union"){
            dsu->Union(x, y);
        }else{
            if(dsu->Find(x) == dsu->Find(y)) cout << "YES";
            else cout << "NO";
            cout << endl;
        }
    }
}