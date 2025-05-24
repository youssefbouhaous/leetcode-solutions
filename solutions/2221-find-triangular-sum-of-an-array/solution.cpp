class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size()>1){
            vector<int>o;
            int n=nums.size();
            for(int i=1;i<n;i++){
                o.push_back((nums[i]+nums[i-1])%10);
            }
            nums=o;
        }
        return nums[0];
    }
};