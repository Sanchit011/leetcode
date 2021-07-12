class Solution {
public:
    
    void dfs(vector<vector<int>>& arr, vector<bool> &vis, int u){
        vis[u] = true;
        for(int i = 0; i<arr.size(); i++){
            if(arr[u][i] == 1){
                if(!vis[i]){
                    dfs(arr, vis, i);
                }
            }
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<bool> vis(n, false);
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(arr, vis, i);
                ans++;
            }
        }
        return ans;
    }
};