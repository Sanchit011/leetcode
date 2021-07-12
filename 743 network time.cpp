class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<long long int> dist(n+1, INT_MAX);
        dist[k] = 0;
        for(int count = 0; count < n-1; count++){
            for(auto edge : times){
                if(dist[edge[1]] > dist[edge[0]] + edge[2]){
                    dist[edge[1]] = dist[edge[0]] + edge[2];
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i<=n; i++){
            if(dist[i] > ans){ans = dist[i];}
        }
        if(ans == INT_MAX){return -1;}
        return ans;
    }
};