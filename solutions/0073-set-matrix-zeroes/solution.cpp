class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>zeros;
        set<int> line;
        set<int> col;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    zeros.push_back({i,j});
                }
            }
        }
        for(int i=0;i<zeros.size();i++){
            int x,y;
            x=zeros[i].first;
            y=zeros[i].second;
            if(line.find(x)==line.end()){
                line.insert(x);
                for(int j=0;j<m;j++){
                    matrix[x][j]=0;
                }
            }
            if(col.find(y)==col.end()){
                col.insert(y);
                for(int j=0;j<n;j++){
                    matrix[j][y]=0;
                }
            }
        }
    }
};