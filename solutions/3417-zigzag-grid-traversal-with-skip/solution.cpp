class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& g) {
        vector<int>ans;
        int n=g.size();
        int m=g[0].size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                for(int j=0;j<m;j+=2){
                    ans.push_back(g[i][j]);
                }
            }
            else{
                for(int j=m-1-m%2;j>-1;j-=2){
                    ans.push_back(g[i][j]);
                }
            }
        }
        return ans;
    }
};