class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int d=1;
        int i=0;
        int j=0;
        int cnt=0;
        int n=mat.size();
        int m=mat[0].size();
        vector<int>ans;
        while(true){
            if(i==n-1 && j==m-1){
                ans.push_back(mat[i][j]);
                break;
            }
            ans.push_back(mat[i][j]);
            if(d==0){
                if(i==n-1){
                    d=1;
                    j++;
                }
                else if(j==0){
                    d=1;
                    i++;
                }
                else{
                    i++,j--;
                }
            }
            else{
                if(j==m-1){
                    d=0;
                    i++;
                }
                else if(i==0){
                    d=0;
                    j++;
                }
                else{
                    i--,j++;
                }
            }
        }
        return ans;
    }
};