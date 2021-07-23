class Solution {
public:
    
    int helper(vector<vector<int>>& dp, vector<int>& arr, int start, int end){
        if(start>end){return 0;}
        if(dp[start][end] != -1){return dp[start][end];}
        int temp;
        int ans = 0;
        int total = 0;
        for(int i = start; i<=end; i++){
            total += arr[i];
        }
        int sum = 0;
        for(int i = start; i<end; i++){
            sum += arr[i];
            if(2*sum < total){
                temp = sum + helper(dp, arr, start, i);
            }
            else if(2*sum > total){
                temp = total - sum + helper(dp, arr, i+1, end);
            }
            else{
                temp = sum + max(helper(dp, arr, start, i), helper(dp, arr, i+1, end));
            }
            ans = max(ans, temp);
        }
        return dp[start][end] = ans;
    }
    
    
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();;
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        int ans = helper(dp, stoneValue, 0, n-1);
        return ans;
    }
};