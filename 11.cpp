class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int left = height[0];
        int right = height[n-1];
        int ans = 0;
        while(i<j){
            left = max(left, height[i]);
            right = max(right, height[j]);
            ans = max(ans, min(left, right)*(j-i));
            if(right >= left){
                i++;
            }
            else j--;
        }
        return ans;
    }
};