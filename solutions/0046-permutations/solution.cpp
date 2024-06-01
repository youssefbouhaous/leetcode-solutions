class Solution {
public:
    vector<vector<int>>ans;
    void f(int i,vector<int>&nums){
        if(i==nums.size()){
            ans.push_back(nums);
        }
        for(int p=i;p<nums.size();p++){
            swap(nums[p],nums[i]);
            f(i+1,nums);
            swap(nums[p],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        f(0,nums);
        return ans;
    }
};