class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int tmp=0;
            for(int j=max(0,i-nums[i]);j<=i;j++){
                tmp+=nums[j];
            }
            ans+=tmp;
        }
        return ans;
    }
};