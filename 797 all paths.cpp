class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> v;
    
    void dfs(vector<vector<int>>& graph, vector<bool>& vis, int curr, int dst){
        vis[curr] = true;
        v.push_back(curr);
        if(curr == dst){
            ans.push_back(v);
        }
        else{
            for(auto next : graph[curr]){
                if(!vis[next]){
                    dfs(graph, vis, next, dst);
                }
            }
        }
        vis[curr] = false;
        v.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        ans.clear();
        v.clear();
        vector<bool> vis(n, false);
        dfs(graph, vis, 0, n-1);
        return ans;
    }
};