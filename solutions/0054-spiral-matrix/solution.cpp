class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        map<pair<int,int>,bool>visited;//a map to check if a given position is visted or not
        vector<int>ans;
        int cntv=0;//count visited positions
        int i=0;int j=0;
        int n=matrix.size();
        int m=matrix[0].size();
        int d=0;
        while(cntv<n*m){
            visited[{i,j}]=true;
            ans.push_back(matrix[i][j]);
            if(d==0 && (j+1==m|| visited[{i,j+1}]) ){
                d=1;
            }
            if(d==1 && (i+1==n|| visited[{i+1,j}] )){
                d=2;
            }
            if(d==2 && (j-1==-1 || visited[{i,j-1}]) ){
                d=3;
            }
            if(d==3 && (i-1==-1|| visited[{i-1,j}] )){
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