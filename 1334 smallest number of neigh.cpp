class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dis) {
        vector<vector<int>> dp(n, vector<int> (n, 10001));
        for(auto ed : edges){
            dp[ed[0]][ed[1]] = ed[2];
            dp[ed[1]][ed[0]] = ed[2];
        }
        for(int i = 0; i<n; i++){
            dp[i][i] = 0;
        }
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        int ans;
        int val = n;
        int count;
        for(int i = 0; i<n; i++){
            count = 0;
            for(int j = 0; j<n; j++){
                if(dp[i][j] <= dis) count++;
            }
            if(count <= val){
                val = count;
                ans = i;
            }
        }
        return ans;
    }
};