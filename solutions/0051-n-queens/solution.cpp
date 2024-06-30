class Solution {
public:
    map<int,bool>col;
    map<int,bool>diag1;
    map<int,bool>diag2;
    int nn;
    vector<vector<string>>ans;
    vector<pair<int,int>>anst;
    void f(int i){
        //cout<<i;
        if(i==nn){
            //cout<<"o";
            vector<string> tmp(nn,string(nn,'.'));
            for(auto x:anst){
                tmp[x.first][x.second]='Q';
            }
            ans.push_back(tmp);
            return;
        }
        for(int j=0;j<nn;j++){
            if(col[j] || diag1[j+i] || diag2[j-i]){
                continue;
            }
            col[j]=diag1[j+i]=diag2[j-i]=true;
            anst.push_back({i,j});
            f(i+1);
            col[j]=diag1[i+j]=diag2[j-i]=false;
            anst.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        nn=n;
        f(0);
        return ans;
    }
};