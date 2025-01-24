#include<bits/stdc++.h>
using namespace std;
class DSU{
    vector<int> parent;
    vector<pair<int, pair<int, int>>> groups; /* {size, min, max} */
public:
    DSU(int n){
        parent.resize(n);
        groups.resize(n);
        int j = 0;
        for(auto &i : parent){
            i = j++;
            groups[j - 1] = {1, {j, j}}; /* initialize with {1, 1, 1} {1, 2, 2} ... */
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
                groups[parent_x].first += groups[parent_y].first;
                groups[parent_x].second.first = min(groups[parent_x].second.first, groups[parent_y].second.first);/* updating min */
                groups[parent_x].second.second = max(groups[parent_x].second.second, groups[parent_y].second.second);/* updating max */
            }else{
                parent[parent_x] = parent_y;
                groups[parent_y].first += groups[parent_x].first;
                groups[parent_y].second.first = min(groups[parent_x].second.first, groups[parent_y].second.first);/* updating min */
                groups[parent_y].second.second = max(groups[parent_x].second.second, groups[parent_y].second.second);/* updating max */
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