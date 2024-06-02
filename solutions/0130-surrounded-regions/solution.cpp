class Solution {
public:
    vector<pair<int,int>>group;
    map<pair<int,int>,bool>visited;
    int n,m;
    bool valid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    void dfs(int i,int j,vector<vector<char>>& board){
        if(!valid(i,j) || visited[{i,j}] || board[i][j]!='O'){
            return;
        }
        visited[{i,j}]=true;
        group.push_back({i,j});
        dfs(i+1,j,board);
        dfs(i-1,j,board);
        dfs(i,j+1,board);
        dfs(i,j-1,board);
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[{i,j}] && board[i][j]=='O'){
                    dfs(i,j,board);
                    bool a=false;
                    bool b=false;
                    bool c=false;
                    bool d=false;
                    bool e=true;
                    for(auto x:group){
                        int xx=x.first;
                        int yy=x.second;
                        vector<pair<int,int>>xy={{xx+1,yy},{xx-1,yy},{xx,yy+1},{xx,yy-1}};
                        int o=0;
                        for(auto r:xy){
                            int ii=r.first;
                            int jj=r.second;
                            if(!valid(ii,jj)){
                                e=false;
                                break;
                            }
                            if(valid(ii,jj) && board[ii][jj]=='X'){
                                if(o==0){
                                    a=true;
                                }
                                if(o==1){
                                    b=true;
                                }
                                if(o==2){
                                    c=true;
                                }
                                if(o==3){
                                    d=true;
                                }
                                
                            }
                            o++;
                        }
                    }
                    if(a&&b&&c&&d&&e){
                        for(auto x:group){
                            //cout<<x.first<<" "<<x.second<<endl;
                            board[x.first][x.second]='X';
                        }
                    }
                    //cout<<a<<b<<c<<d<<endl;
                    //visited.clear();
                    group.clear();
                }
            }
        }
    }
};