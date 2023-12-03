class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c=0;
        for(auto x:nums){
            if(x==0){
                c++;
            }
        }
        int n=nums.size();
        for(int i=n-1;i>-1;i--){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
            }
        }
        while(c--){
            nums.push_back(0);
        }
    }
};