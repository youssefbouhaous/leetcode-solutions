#define ll long long int
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        map<ll,ll>d;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>left(n,vector<int>(m));
        vector<vector<int>>right(n,vector<int>(m));
        vector<vector<int>>up(n,vector<int>(m));
        vector<vector<int>>bot(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                left[i][j]= (j>0 ? left[i][j-1] :0)+grid[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=m-1;j>-1;j--){
                right[i][j]= (j<m-1 ? right[i][j+1]: 0)+grid[i][j];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                up[i][j]= (i>0 ? up[i-1][j] : 0)+grid[i][j];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=n-1;i>-1;i--){
                bot[i][j]= (i<n-1 ? bot[i+1][j] : 0)+grid[i][j];
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)
                continue;


                int c1 = ((bot[i][j]-1)*(left[i][j]-1));
                    
                int c2 = ((bot[i][j]-1)*(right[i][j]-1));

                int c3 = ((up[i][j]-1)*(left[i][j]-1));

                int c4 = ((up[i][j]-1)*(right[i][j]-1));

                ans += (c1+c2+c3+c4);
            }
        }
        
        return ans;
    }
};