#include<bits/stdc++.h>
using namespace std;
class DSU{
    vector<int> parent;
    vector<int> experience;
public:
    DSU(int n){
        parent.resize(n);
        experience.resize(n);
        int j = 0;
        for(auto &i : parent){
            i = j++;
        }
    }

    int Find(int x){
        if(parent[x] == x) return x;
        return parent[x] = Find(parent[x]);
    }

    pair<int, pair<int, int>> Get(int x){
        return groups[x];
    }

    bool Union(int x, int y){
        int parent_x = Find(x);
        int parent_y = Find(y);
        if(parent_x != parent_y){ /* Different parents so do union */
            if(parent_x < parent_y){
                parent[parent_y] = parent_x;
            }else{
                parent[parent_x] = parent_y;
            }
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
    DSU* dsu = new DSU(n);
    while(m--){
        string op;
        int x, y;
        cin >> op >> x;
        if(op == "union"){
            cin >> y;
            dsu->Union(x - 1, y - 1);
        }else{
            pair<int, pair<int, int>> res = dsu->Get(dsu->Find(x - 1));
            cout << res.second.first << " " << res.second.second << " " << res.first << endl;
        }
    }
}