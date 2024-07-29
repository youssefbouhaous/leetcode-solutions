class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        vector<int>preMax(n);
        vector<int>preMin(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(rating[i]>rating[j])
                    preMin[i]++;
                else
                    preMax[i]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(rating[i]>rating[j]){
                    ans+=preMin[j];
                }
                else
                    ans+=preMax[j];
            }
        }
        return ans;
    }
};