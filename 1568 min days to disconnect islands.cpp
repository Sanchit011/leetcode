class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &vis, int i, int j){
        vis[i][j] = true;
        if(i>0 && !vis[i-1][j] && grid[i-1][j] == 1){dfs(grid, vis, i-1, j);}
        if(j>0 && !vis[i][j-1] && grid[i][j-1] == 1){dfs(grid, vis, i, j-1);}
        if(i<grid.size()-1 && !vis[i+1][j]  && grid[i+1][j] == 1){dfs(grid, vis, i+1, j);}
        if(j<grid[0].size()-1 && !vis[i][j+1]  && grid[i][j+1] == 1){dfs(grid, vis, i, j+1);}
        return;
    }
    
    int check(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    dfs(grid, vis, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    
    int minDays(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int x = check(grid);
        if(x != 1){return 0;}
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    int val = check(grid);
                    if(val != 1){return 1;}
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};

