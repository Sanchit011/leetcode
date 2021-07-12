class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 1){return 0;}
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 0;
        right[n-1] = 0;
        int mx_left = height[0];
        int mx_right = height[n-1];
        for(int i = 1; i<n; i++){
            left[i] = mx_left;
            mx_left = max(mx_left, height[i]);
        }
        for(int i = n-2; i>=0; i--){
            right[i] = mx_right;
            mx_right = max(mx_right, height[i]);
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            int val = min(left[i], right[i]) - height[i];
            ans += max(0, val);
        }
        return ans;
    }
};