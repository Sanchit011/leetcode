class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>> &adj, int parent, vector<int> &dis, vector<int> &low, int u, int &time){
        if(dis[u] == -1){
            dis[u] = time;
            time++;
            low[u] = dis[u];
        }
        for(auto v : adj[u]){
            if(v == parent){continue;}
            if(dis[v] == -1){
                dfs(adj, u, dis, low, v, time);
                low[u] = min(low[u], low[v]);
                if(low[v] > dis[u]){
                    ans.push_back({u, v});
                }
            }
            if(dis[v] != -1){
                low[u] = min(low[u], dis[v]);
            }
            
        }
        return;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n, vector<int>(0));
        for(int i = 0; i<connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        ans.clear();
        int time = 1;
        vector<int> dis(n, -1);
        vector<int> low(n, INT_MAX);
        dfs(adj, -1, dis, low, 0, time);
        return ans;
    }
};