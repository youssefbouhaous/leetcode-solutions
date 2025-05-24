class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int a=*max_element(nums.begin(),nums.end());
        int b=*min_element(nums.begin(),nums.end());
        return max(0,a-b-2*k);
    }
};