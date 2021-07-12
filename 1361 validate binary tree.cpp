class Solution {
public:
    
    vector<int> parent;
    
    int find(int x){
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void uni(int x, int y){
        int p1 = find(x);
        int p2 = find(y);
        parent[p2] = p1;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        parent.clear();
        for(int i = 0; i<n; i++){
            parent.push_back(i);
        }
        for(int i = 0; i<n; i++){
            int l = left[i];
            int r = right[i];
            if(l != -1 && find(l) == find(i)){return false;}
            if(r != -1 && find(r) == find(i)){return false;}
            if(l != -1 && find(l) != l){return false;}
            if(r != -1 && find(r) != r){return false;}
            if(l != -1) uni(i, l);
            if(r != -1) uni(i, r);
        }
        int count = 0;
        for(int i = 0; i<n; i++){
            if(parent[i] == i){count++;}
        }
        if(count != 1) return false;
        return true;
    }
};