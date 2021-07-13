class Solution {
public:
    
    void dfs(string s, unordered_map<string, int>& map, vector<string>& arr, vector<string>& ans){
        if(s.size() == 0){
            string str = "";
            for(auto x : arr){
                str += x + " ";
            }
            str.pop_back();
            ans.push_back(str);
            return;
        }
        int n = s.size();
        for(int i = 0; i<n; i++){
            string a = s.substr(0, i+1);
            string b = s.substr(i+1, n-i-1);
            if(map.find(a) != map.end()){
                arr.push_back(a);
                dfs(b, map, arr, ans);
                arr.pop_back();
            }
        }
        return;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> map;
        for(auto word : wordDict){
            map[word]++;
        }
        vector<string> ans;
        vector<string> arr;
        dfs(s, map, arr, ans);
        return ans;
    }
};