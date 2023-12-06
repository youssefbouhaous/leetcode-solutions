class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int tmp=0;
        for(auto x:gain){
            tmp+=x;
            ans=max(ans,tmp);
        }
        return ans;
    }
};