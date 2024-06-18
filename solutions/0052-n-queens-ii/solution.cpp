class Solution {
public:
    map<int,bool>cols;
    map<int,bool>diag1;
    map<int,bool>diag2;
    int n;
    int ans=0;
    void dfs(int i){
        if(i==n){
            ans++;
            return;
        }
        for(int j=0;j<n;j++){
            if(cols[j] || diag1[i+j] || diag2[j-i-1]){
                continue;
            }
            cols[j]=diag1[i+j]=diag2[j-i-1]=true;
            dfs(i+1);
            cols[j]=diag1[i+j]=diag2[j-i-1]=false;
        }
    }
    int totalNQueens(int nn) {
        n=nn;
        dfs(0);
        return ans;
    }
};