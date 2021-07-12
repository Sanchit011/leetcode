class Solution {
public:
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int val){
        if(val <= dp[i][j]){return dp[i][j];}
        dp[i][j] = val;
        if(i>0 && matrix[i-1][j]>matrix[i][j]){
            int a = dfs(matrix, dp, i-1, j, 1 + dp[i][j]);
        }
        if(i<matrix.size()-1 && matrix[i+1][j]>matrix[i][j]){
            int b = dfs(matrix, dp, i+1, j, 1 + dp[i][j]);
        }
        if(j>0 && matrix[i][j-1]>matrix[i][j]){
            int c = dfs(matrix, dp, i, j-1, 1 + dp[i][j]);
        }
        if(j<matrix[0].size()-1 && matrix[i][j+1]>matrix[i][j]){
            int d = dfs(matrix, dp, i, j+1, 1 + dp[i][j]);
        }
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                dp[i][j] = dfs(matrix, dp, i, j, 1);
            }
        }
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(ans < dp[i][j]){
                    ans = dp[i][j];
                }
            }
        }
        return ans;
    }
};