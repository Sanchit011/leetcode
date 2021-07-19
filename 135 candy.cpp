class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1){return 1;}
        vector<int> arr(n, 1);
        for(int i = 0; i<n-1; i++){
            if(ratings[i+1] > ratings[i]){
                arr[i+1] = 1 + arr[i];
            }
        }
        for(int i = n-1; i>0; i--){
            if(ratings[i-1] > ratings[i]){
                arr[i-1] = max(1 + arr[i], arr[i-1]);
            }
        }
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }
        return sum;
    }
};