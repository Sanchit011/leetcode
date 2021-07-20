class Solution {
public:
    
    int ans;
    
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int count){
        vis[i][j] = true;
        if(grid[i][j] == 2){
            if(count == 0){ans++;}
            vis[i][j] = false;
            count++;
            return;
        }
        vector<int> xx = {1, -1, 0, 0};
        vector<int> yy = {0, 0, 1, -1};
        for(int k = 0; k<4; k++){
            int x = i+xx[k];
            int y = j+yy[k];
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && !vis[x][y] && grid[x][y] != -1){
                dfs(x, y, grid, vis, count-1);
            }
        }
        vis[i][j] = false;
        return;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        ans = 0;
        int count = n*m - 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == -1){
                    count--;
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid, vis, count);
                }
            }
        }
        return ans;
    }
};