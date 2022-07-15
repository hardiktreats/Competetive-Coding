class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int  m= grid.size(), n=grid[0].size(),maxi=0; 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int count = 1;
                    count_island(grid,i,j,count);
                    maxi = max(maxi,count);
                    }
                }
            }
            return maxi;
        }
        int count_island(vector<vector<int>>& grid, int i, int j,int & count){        
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()){
            return 0;
        }
            if(grid[i][j]==0) return 0;
            grid[i][j]=0;
            if(count_island(grid,i-1,j,count)==1) count++;
            if(count_island(grid,i,j-1,count)==1) count++;
            if(count_island(grid,i+1,j,count)==1) count++;
            if(count_island(grid,i,j+1,count)==1) count++;
        return 1;
    } 
};