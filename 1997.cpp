class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& arr) {
        int n = arr.size();
        long long mod = 1000000007;
        vector<long long> dp(n, 0);
        dp[0] = 2;
        for(int i = 1; i<n; i++){
            dp[i] = dp[i-1];
            if(arr[i] == 0){
                dp[i] += (2 + dp[i-1])%mod;
                dp[i] %= mod;
            }
            else{
                dp[i] = (dp[i-1] + 2)%mod;
                dp[i] += (dp[i-1] - dp[arr[i]-1] + mod)%mod;
                dp[i] %= mod;
            }
        }
        return dp[n-2];
    }
};