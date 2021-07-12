class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> ind(n, 0);
        for(int i = 0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            ind[pre[i][0]]++;
        }
        queue<int> q;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(ind[i] == 0){
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto v : adj[x]){
                ind[v]--;
                if(ind[v] == 0){
                    count++;
                    q.push(v);
                }
            }
        }
        return count == n;
    }
};