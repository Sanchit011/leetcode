class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 2){return {0, 1};}
        int count = 0;
        vector<vector<int>> adj(n);
        vector<int> ind(n, -1);
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            ind[edges[i][0]]++;
            ind[edges[i][1]]++;
        }
        vector<int> v;
        vector<bool> vis(n, false);
        for(int i = 0; i<n; i++){
            if(ind[i] == 0){
                v.push_back(i);
                vis[i] = true;
            }
        }
        n -= v.size();
        while(n>2){
            vector<int> temp;
            for(auto u : v){
                for(auto c : adj[u]){
                    ind[c]--;
                    if(ind[c] == 0){
                        temp.push_back(c);
                        vis[c] = true;
                    }
                }
            }
            v = temp;
            n -= v.size();
        }
        vector<int> ans;
        for(int i = 0; i<vis.size(); i++){
            if(!vis[i]){ans.push_back(i);}
        }
        return ans;
    }
};