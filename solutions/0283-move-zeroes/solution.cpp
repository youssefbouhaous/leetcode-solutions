class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c=0;
        int n=nums.size();
        for(int i=n-2;i>-1;i--){
            if(nums[i]==0){
                for(int j=i;j<n-1;j++){
                    swap(nums[j],nums[j+1]);
                }
            }
        }
    }
};