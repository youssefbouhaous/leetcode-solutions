class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(nums[n/2]>k){
            for(int i=n/2;i>-1;i--){
                if(nums[i]<=k){
                    break;
                }
                else{
                    ans+=nums[i]-k;
                }
            }
        }
        else{
            for(int i=n/2;i<n;i++){
                if(nums[i]>=k){
                    break;
                }
                else{
                    ans+=-nums[i]+k;
                }
            }
        }
        return ans;
    }
};