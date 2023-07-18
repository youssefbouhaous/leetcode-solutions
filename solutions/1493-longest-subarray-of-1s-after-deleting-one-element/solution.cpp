class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int ans=0;
        int c=0;
        int n=nums.size();
        while(j<n){
            if(nums[j]==0){
                c++;
                while(c>1){
                    if(nums[i]==0){
                        c--;
                    }
                    i++;
                }
            }
            j++;
            ans=max(ans,j-i-1);
        }
        return ans;
    }
};