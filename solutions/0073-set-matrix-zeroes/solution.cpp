class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>rowsToZero;
        set<int>colsToZero;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    rowsToZero.insert(i);
                    colsToZero.insert(j);
                }
            }
        }
        for(auto x:colsToZero){
            for(int i=0;i<n;i++){
                matrix[i][x]=0;
            }
        }
        for(auto x:rowsToZero){
            for(int i=0;i<m;i++){
                matrix[x][i]=0;
            }
        }
    }
};