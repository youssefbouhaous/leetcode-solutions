class Solution {
public:
    int minCostToMoveChips(vector<int>& p) {
        int ans=INT_MAX;
        int n=p.size();
        for(int i=0;i<n;i++){
            int tmp=0;
            for(int j=0;j<n;j++){
                if(j!=i){
                    tmp+=abs(p[i]-p[j])%2;
                }
            }
            ans=min(ans,tmp);
        }
        return ans;
    }
};