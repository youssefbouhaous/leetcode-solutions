class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int l=0;
        int r=nums.size()-1;
        int c=0;
        sort(nums.begin(),nums.end());
        while(l<r){
            if(nums[l]+nums[r]==k){
                c++;
                r--,l++;
            }
            else if(nums[l]+nums[r]<k){
                l++;
            }
            else if(nums[l]+nums[r]>k){
                r--;
            }
        }
        return c;
    }
};