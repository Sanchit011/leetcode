class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<int> pos;
        vector<int> neg;
        for(auto el : satisfaction){
            if(el<0) neg.push_back(el);
            else pos.push_back(el);
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        int n = neg.size();
        long long ans = 0;
        long long sum;
        for(int i = 0; i<=n; i++){
            sum = 0;
            int x = neg.size();
            for(int j = x-i; j<x; j++){
                sum += (j-x+i+1)*neg[j];
            }
            for(int j = 0; j<pos.size(); j++){
                sum += (j+i+1)*pos[j];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};