class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans;
        if(nums.size()==1){
            ans.push_back(-1);
            return ans;
        }
        else if(nums.size()==2){
            if(nums[0]==nums[1]){
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }
            else if(nums[0]>nums[1]){
                ans.push_back(-1);
                ans.push_back(nums[0]);
            }
            else{
                ans.push_back(nums[1]);
                ans.push_back(-1);
            }
        }
        int m=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=i+1;
            j=j%n;
            while(nums[j]!=m){
                if(nums[j]>nums[i]){
                    ans.push_back(nums[j]);
                    break;
                }
                j++;
                j=j%n;
            }
            if(ans.size()<i+1 && nums[i]!=m){
                ans.push_back(m);
            }
            else if(ans.size()<i+1){
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};