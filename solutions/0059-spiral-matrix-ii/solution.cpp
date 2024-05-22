class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int element=1;
        int d=0;
        vector<vector<int>>ans(n,vector<int>(n));
        int i=0;
        int j=0;
        vector<vector<bool>>visited(n,vector<bool>(n));
        int cntv=0;
        while(cntv<n*n){
            visited[i][j]=true;
            ans[i][j]=element;
            element++;
            if(d==0 && (j+1==n || visited[i][j+1])){
                d=1;
            }
            if(d==1 && (i+1==n || visited[i+1][j])){
                d=2;
            }
            if(d==2 && (j-1==-1 || visited[i][j-1])){
                d=3;
            }
            if(d==3 && (i-1==-1 || visited[i-1][j])){
                d=0;
            }
            if(d==0){
                j++;
            }
            if(d==1){
                i++;
            }
            if(d==2){
                j--;
            }
            if(d==3){
                i--;
            }
            cntv++;
        }
        return ans;
    }
};