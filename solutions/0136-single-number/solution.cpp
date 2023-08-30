class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r=0;
        for(auto x:nums){
            r^=x;
        }
        return r;
    }
};