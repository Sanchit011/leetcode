class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int curr, int req){
        if(vis[curr] != 0){
            return vis[curr] == req;    
        }
        vis[curr] = req;
        for(auto next : graph[curr]){
            if(!dfs(graph, vis, next, -req)){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<int> vis(n, 0);
        for(int i = 0; i<n; i++){
            if(vis[i] == 0){
                if(!dfs(graph, vis, i, 1)){
                    return false;
                }
            }
        }
        return true;
    }
};