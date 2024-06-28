class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int xmax=0;
        int ymax=0;
        int n=grid.size();
        int m=grid[0].size();
        int xmin=n+2;
        int ymin=m+2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    xmin=min(i,xmin);
                    xmax=max(i,xmax);
                    ymin=min(ymin,j);
                    ymax=max(ymax,j);
                }
            }
        }
        return (xmax-xmin+1)*(ymax-ymin+1);
    }
};