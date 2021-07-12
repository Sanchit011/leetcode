class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;
    
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        else return parent[x] = find(parent[x]);
    }
    
    void uni (int x, int y){
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
    }
    
    bool equationsPossible(vector<string>& equations) {
        int n = 26;
        parent.clear();
        rank.clear();
        for(int i = 0; i<n; i++){
            parent.push_back(i);
            rank.push_back(1);
        }
        for(auto eq : equations){
            if(eq[1] == '='){
                uni(eq[0]-'a', eq[3]-'a');
            }
        }
        for(auto eq : equations){
            if(eq[1] == '!'){
                if(find(eq[0]-'a') == find(eq[3]-'a')) return false;
            }
        }
        return true;
    }
};