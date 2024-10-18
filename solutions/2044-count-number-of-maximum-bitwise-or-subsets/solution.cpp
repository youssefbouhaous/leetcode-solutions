class Solution {
    int m=0;
    int f(int o,int i,vector<int>&nums){
        //cout<<'o'<<o<<" i "<<i<<endl;
        if(nums.size()<=i) return 0;
        if((o|nums[i])==m) return 1+f(o,i+1,nums)+f((o|nums[i]),i+1,nums);
        return f(o,i+1,nums)+f((o|nums[i]),i+1,nums);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        for(auto& x:nums){
            m|=x;
        }
        return f(0,0,nums);
    }
};