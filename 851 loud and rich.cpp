class Solution {
public:
    
    int dfs(vector<vector<int>> &adj, vector<int>& quiet, vector<int> &ans, int curr){
        if(ans[curr] != -1){return ans[curr];}
        ans[curr] = curr;
        for(auto next : adj[curr]){
            if(quiet[dfs(adj, quiet, ans, next)] < quiet[ans[curr]]){
                ans[curr] = ans[next];
            }
        }
        return ans[curr];
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        for(auto x : richer){
            int high = x[0];
            int low = x[1];
            adj[low].push_back(high);
        }
        vector<int> ans(n, -1);
        for(int i = 0; i<n; i++){
            ans[i] = dfs(adj, quiet, ans, i);
        }
        return ans;
    }
};