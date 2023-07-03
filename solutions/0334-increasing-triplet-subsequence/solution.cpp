class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
                if(ans.size()>2){
                    return true;
                }
            }
            else{
                if(nums[i]<ans[0]){
                    ans[0]=nums[i];
                }
                else if(ans.size()>1 && nums[i]<ans[1] && ans[0]!=nums[i]){
                    ans[1]=nums[i];
                }
            }
        }
        return ans.size()>2;
    }
};