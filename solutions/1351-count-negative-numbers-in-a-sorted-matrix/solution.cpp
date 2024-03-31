class Solution {
public:
    int countNegatives(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            int l=0;
            int r=m-1;
            int tmp=m;
            while(l<=r){
                int m=(l+r)/2;
                if(g[i][m]<0){
                    r=m-1;
                    tmp=m;
                }
                else{
                    l=m+1;
                }
            }
            ans+=m-tmp;
        }
        return ans;
    }
};