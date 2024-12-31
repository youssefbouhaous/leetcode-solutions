class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res=1;
        int n=nums.size();
        if(n==1)return 1;
        int s=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1] && s!=-1) {
                s=-1;
                res++;
            }
            else if(nums[i]>nums[i-1] && s!=1){
                s=1;
                res++;
            }
        }
        return res;
    }
};