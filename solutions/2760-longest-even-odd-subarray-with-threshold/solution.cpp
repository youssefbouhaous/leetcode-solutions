class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int t) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0 || nums[i]>t){
                continue;
            }
            else{
                ans=max(ans,1);
                for(int j=i+1;j<n;j++){
                    if(nums[j]%2!=nums[j-1]%2 && nums[j]<=t){
                        ans=max(ans,j-i+1);
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};