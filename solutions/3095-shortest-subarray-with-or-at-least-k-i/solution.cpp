class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int tmp=nums[i];
            for(int j=i;j<n;j++){
                tmp|=nums[j];
                if(tmp>=k){
                    ans= (ans==-1) ? j-i+1 : min(j-i+1,ans);
                }
            }
        }
        return ans;
    }
};