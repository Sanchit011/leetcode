class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string, int> map;
        for(auto word : wordDict){
            map[word]++;
        }
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 1; i<n+1; i++){
            for(int j = 0; j<i; j++){
                if(dp[j] && map.find(s.substr(j, i-j)) != map.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};