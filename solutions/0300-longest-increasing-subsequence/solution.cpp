class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int l=0;int r=ans.size()-1;
                while(l<r){
                    int m=(l+r)/2;
                    if(ans[m]>=nums[i]) r=m;
                    else l=m+1;
                }
                ans[l]=nums[i];
            }
        }
        return ans.size();
    }
};