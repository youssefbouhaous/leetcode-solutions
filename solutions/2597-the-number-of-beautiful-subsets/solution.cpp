class Solution {
public:

    vector<vector<int>>sub;
    vector<int>per;
    void f(int i,vector<int>& nums){
        if(i==nums.size()){
            if(!per.empty())
            sub.push_back(per);
            return;
        }
        per.push_back(nums[i]);
        f(i+1,nums);
        per.pop_back();
        f(i+1,nums);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        f(0,nums);
        int ans=0;
        for(auto x:sub){
            bool isValide=true;
            for(int i=0;i<x.size();i++){
                for(int j=0;j<x.size();j++){
                    if(i!=j && abs(x[i]-x[j])==k){
                        isValide=false;
                    }
                }
            }
            if(isValide){
                ans++;
            }
        }
        return ans;
    }
};