class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(auto x:nums){
            bool f=false;
            for(int i=1;i<=1000;i++){
                if((i|(i+1))==x){
                    ans.push_back(i);
                    f=true;
                    break;
                }
            }
            if(!f){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};