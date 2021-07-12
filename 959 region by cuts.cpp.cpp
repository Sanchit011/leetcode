class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;
    
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    
    void uni(int x, int y){
        int p1 = find(x);
        int p2 = find(y);
        if(p1 == p2){return;}
        if(rank[p1] >= rank[p2]){
            parent[p2] = p1;
            rank[p1]++;
        }
        else{
            parent[p1] = p2;
            rank[p2]++;
        }
        return;
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        parent.clear();
        rank.clear();
        for(int i = 0; i<4*n*n; i++){
            parent.push_back(i);
            rank.push_back(1);
        }
        for(int i = 0; i<n; i++){
            string str = grid[i];
            int index = 0;
            int val;
            int j = 0;
            for(int j = 0; j<n; j++){
                val = 4*i*n + 4*j;
                if(str[j] == '\\'){
                    uni(val, val+1);
                    uni(val+2, val+3);
                }
                else if(str[j] == '/'){
                    uni(val, val+3);
                    uni(val+1, val+2);
                }
                else{
                    uni(val, val+1);
                    uni(val, val+2);
                    uni(val, val+3);
                }
                if(val + 7 < 4*n*(i+1)){
                    uni(val+1, val+7);
                }
                if(val + 4*n < 4*n*n){
                    uni(val+2, val + 4*n);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<4*n*n; i++){
            if(parent[i] == i){
                ans++;
            }
        }
        return ans;
    }
};