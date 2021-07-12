class Solution {
public:
    
    void helper(string curr, unordered_map<string, multiset<string>> &adj, vector<string> &ans){
        while(adj[curr].size() > 0){
            string next = *adj[curr].begin();
            adj[curr].erase(adj[curr].begin());
            helper(next, adj, ans);
        }
        ans.push_back(curr);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;
        for(auto ticket : tickets){
            adj[ticket[0]].insert(ticket[1]);
        }
        vector<string> ans;
        helper("JFK", adj, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};