class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int meh=nums[0];//maximum ending in the current position
        int ans=nums[0];//our anwser
        for(int i=1;i<nums.size();i++){
            if(meh +nums[i]<nums[i]){
                meh=nums[i];
            }
            else{
                meh+=nums[i];
            }
            ans=max(ans,meh);
        }
        return ans;
    }
};