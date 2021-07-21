/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* helper(vector<pair<int, int>>& arr, int d, int start, int end){
        if(start >= end){return NULL;}
        TreeNode* root = new TreeNode(arr[start].second);
        int index = end;
        for(int i = start+2; i<end; i++){
            if(arr[i].first == d+1){
                index = i;
                break;
            }
        }
        root->left = helper(arr, d+1, start+1, index);
        root->right = helper(arr, d+1, index, end);
        return root;
    }
    
    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int, int>> arr;
        int i = 0;
        int n = traversal.size();
        while(i<n){
            int count = 0;
            while(traversal[i] == '-'){
                count++;
                i++;
            }
            int temp = 0;
            while(traversal[i] != '-' && i<n){
                int x = traversal[i] - '0';
                temp = temp*10 + x;
                i++;
            }
            arr.push_back({count, temp});
        }
        return helper(arr, 0, 0, arr.size());
    }
};