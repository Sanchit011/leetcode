class Solution {
public:
    
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int i){
        vis[i] = true;
        for(auto next : adj[i]){
            if(!vis[next]){
                dfs(adj, vis, next);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int x = connections.size();
        if(x < n-1){return -1;}
        vector<vector<int>> adj(n);
        for(auto x : connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> vis(n, false);
        int count = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(adj, vis, i);
                count++;
            }
        }
        return count - 1;
    }
};