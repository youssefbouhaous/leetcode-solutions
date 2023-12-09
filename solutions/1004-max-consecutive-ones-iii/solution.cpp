class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int kk=k;
        int n=nums.size();
        int l=0;
        int r=0;
        int ans=0;
        while(r<n){
            if(nums[r]==0)kk--;
            if(kk<0){
                if(nums[l]==0)kk++;
                l++;
            }
            r++;
            ans=max(ans,r-l);
        }
        return ans;
    }
};