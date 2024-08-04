class neighborSum {
public:
    vector<vector<int>>v;
    neighborSum(vector<vector<int>>& grid) {
        v=grid;
    }
    
    int adjacentSum(int x) {
        int ans=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==x){
                    vector<pair<int,int>>xy={{i+1,j},{i-1,j},{i,j+1},{i,j-1}};
                    
                    for(auto u:xy){
                        if(u.first>=0 && u.first<v.size() && u.second>=0 && u.second<v[0].size()){
                            ans+=v[u.first][u.second];
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
    
    int diagonalSum(int x) {
        int ans=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==x){
                    vector<pair<int,int>>xy={{i+1,j+1},{i-1,j-1},{i-1,j+1},{i+1,j-1}};
                    
                    for(auto u:xy){
                        if(u.first>=0 && u.first<v.size() && u.second>=0 && u.second<v[0].size()){
                            ans+=v[u.first][u.second];
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */