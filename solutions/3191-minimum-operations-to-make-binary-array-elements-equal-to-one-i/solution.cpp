class Solution {
public:
    int minOperations(vector<int>& nums) {
        int zero=0;
        int one=0;
        for(auto x:nums){
            if(x==0){
                zero++;
            }
            else{
                one++;
            }
        }
        if(zero==0){
            return 0;
        }
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-2;i++){
            if(nums[i]==1){
                continue;
            }
            else{
                nums[i]=1;
                nums[i+1]=1-nums[i+1];
                nums[i+2]=1-nums[i+2];
                ans++;
            }
        }
        if(nums[n-1]==0 || nums[n-2]==0){
            return -1;
        }
        return ans;
    }
};