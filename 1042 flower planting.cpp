class Solution {
public:
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        for(auto p : paths){
            adj[p[0]-1].push_back(p[1]-1);
            adj[p[1]-1].push_back(p[0]-1);
        }
        for(int i = 0; i<n; i++){
            vector<bool> col(5, false);
            for(auto next : adj[i]){
                col[vis[next]] = true;
            }
            for(int j = 1; j<5; j++){
                if(!col[j]){
                    vis[i] = j;
                    break;
                }
            }
        }
        return vis;
    }
};