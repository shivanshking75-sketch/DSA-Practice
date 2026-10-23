class Solution {
public:
    int row, col;
    int dx[4]={-1,1,0,0}, dy[4]={0,0,1,-1};

    int dfs(vector<vector<int>>& grid, int x, int y){
        if(x<0 || y<0 || x>=row || y>=col || grid[x][y]!=1) return 0;
        grid[x][y]=-1; // -1 means we visted {i,j}
        int area = 1;
        for(int dir = 0; dir < 4; dir++) area += dfs(grid, x+dx[dir], y+dy[dir]);
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]==1){
                    int curArea = dfs(grid,i,j);
                    ans = max(ans, curArea);
                }
            }
        }
        return ans;
    }
};