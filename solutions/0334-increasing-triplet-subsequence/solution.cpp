class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
                if(ans.size()==3){
                    return true;
                }
            }
            else{
                for(int j=0;j<ans.size();j++){
                    if(nums[i]<ans[j]){
                        ans[j]=nums[i];
                        break;
                    }
                    else if(nums[i]==ans[j]){
                        break;
                    }
                }
            }
        }
        return ans.size()==3;
    }
};