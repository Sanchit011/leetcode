class Solution {
public:
    
    unordered_set<int> safe;
    unordered_set<int> cycle;
    
    bool dfs(vector<vector<int>>& graph, vector<bool> &vis, int curr){
        if(cycle.find(curr) != cycle.end()){return false;}
        if(safe.find(curr) != safe.end()){return true;}
        
        if(vis[curr]){
            cycle.insert(curr);
            return false;
        }
        vis[curr] = true;
        for(auto next : graph[curr]){
            if(!dfs(graph, vis, next)){
                cycle.insert(next);
                return false;
            }
        }
        safe.insert(curr);
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<int> ans;
        for(int i = 0; i<n; i++){
            if(dfs(graph, vis, i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};