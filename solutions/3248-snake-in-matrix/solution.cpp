class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=i*n+j;
            }
        }
        int ans=0;
        int i=0;int j=0;
        for(auto x:commands){
            if(x=="UP"){
                i--;
            }
            if(x=="RIGHT"){
                j++;
            }
            if(x=="DOWN"){
                i++;
            }
            if(x=="LEFT"){
                j--;
            }
        }
        return grid[i][j];
    }
};