class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>d;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(d[target-nums[i]]!=0){
                ans={d[target-nums[i]]-1,i};
            }
            d[nums[i]]=i+1;
        }
        return ans;
    }
};