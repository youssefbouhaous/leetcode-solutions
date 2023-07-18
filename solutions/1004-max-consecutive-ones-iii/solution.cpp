class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int i=0;
        int j=0;
        int c=0;
        int n=nums.size();
        while(j<n){
            if(nums[j]==0){
                c++;
                if(c>k){
                    while(c>k){
                        if(nums[i]==0){
                            c--;
                        }
                        i++;
                    }
                }
            }
            j++;
            ans=max(ans,j-i);
        }
        return ans;
    }
};