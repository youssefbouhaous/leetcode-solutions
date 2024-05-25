class Solution {
public:
    int n,m;
    bool valid(pair<int,int>&x,int i,int j){
        return x.first+i>-1 && x.second+j>-1 && x.first+i<n && x.second+j<m; 
    }
    void gameOfLife(vector<vector<int>>& board) {
        n=board.size();
        m=board[0].size();
        vector<vector<int>>next(n,vector<int>(m));
        vector<pair<int,int>>xy={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                for(auto x:xy){
                    if(valid(x,i,j) && board[x.first+i][x.second+j]==1){
                        cnt++;
                    }
                }
                if(board[i][j]==1 && (cnt==2 || cnt==3)){
                    next[i][j]=1;
                }
                if(board[i][j]==0 && cnt==3){
                    next[i][j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]=next[i][j];
            }
        }
    }
};