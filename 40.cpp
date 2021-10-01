class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    
    void helper(vector<int>& candidates, int target, int sum, int curr){
        if(sum == target){
            ans.push_back(v);
            return;
        }
        int n = candidates.size();
        if(curr >= n) return;
        for(int i = curr; i<n; i++){
            if(i > curr && candidates[i] == candidates[i-1]) continue;
            if(sum + candidates[i] > target) break;
            v.push_back(candidates[i]);
            helper(candidates, target, sum + candidates[i], i+1);
            v.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        v.clear();
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, 0);
        return ans;
    }
};