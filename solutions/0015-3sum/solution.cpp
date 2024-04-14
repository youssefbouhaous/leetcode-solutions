class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                if(nums[i]==-nums[l]-nums[r]){
                    ans.insert({nums[i],nums[l],nums[r]});
                    r--;
                }
                else if(nums[i]>-nums[l]-nums[r]){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        vector<vector<int>>fans;
        for(auto x:ans){
            fans.push_back(x);
        }
        return fans;
    }
};