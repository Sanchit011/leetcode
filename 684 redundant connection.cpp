class Solution {
public:
    
    int parent[1002];
    int rank[1002];
    
    void init(int n){
        for(int i = 0; i<=n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        else{
            return parent[x] = find(parent[x]);
        }
    }
    
    void uni(int a, int b){
        int p1 = parent[a];
        int p2 = parent[b];
        if(p1 == p2){return;}
        if(rank[p1] >= rank[p2]){
            parent[p2] = p1;
            rank[p1] = max(rank[p1], rank[p2]+1);
            return;
        }
        parent[p1] = p2;
        rank[p2] = max(rank[p2], rank[p1]+1);
        return;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        init(n);
        vector<int> ans = {-1, -1};
        for(auto edge : edges){
            int a = edge[0];
            int b = edge[1];
            if(find(a) == find(b)){
                ans = edge;
            }
            uni(a, b);
        }
        return ans;
    }
};