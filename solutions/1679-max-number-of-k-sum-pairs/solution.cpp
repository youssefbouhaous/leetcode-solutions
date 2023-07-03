class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0;
        int lp=0;
        int rp=nums.size()-1;
        sort(nums.begin(),nums.end());
        while(lp<rp){
            if(nums[lp]+nums[rp]==k){
                lp++;
                rp--;
                ans++;
            }
            else if(nums[lp]+nums[rp]<k){
                lp++;
            }
            else{
                rp--;
            }
        }
        return ans;
    }
};