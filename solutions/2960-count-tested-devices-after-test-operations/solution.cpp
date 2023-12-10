class Solution {
public:
    int countTestedDevices(vector<int>& b) {
        int ans=0;
        int k=0;
        for(auto x:b){
            if(x-k>0){
                ans++;
                k++;
            }
        }
        return ans;
    }
};