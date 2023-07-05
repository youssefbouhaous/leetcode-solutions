class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int m=0;
        int ans=0;
        for(int i=0;i<gain.size();i++){
            m+=gain[i];
            ans=max(ans,m);
        }
        return ans;
    }
};