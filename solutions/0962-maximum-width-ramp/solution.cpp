class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        set<int>st;
        for(int j=0;j<n;j++){
            if(!st.empty() && (*st.begin())>nums[j]){
                st.insert(nums[j]);
                continue;
            }
            st.insert(nums[j]);
            for(int i=0;i<j;i++){
                if(nums[i]<=nums[j]){
                    ans=max(ans,j-i);
                    break;
                }
            }
        }
        return ans;
    }
};