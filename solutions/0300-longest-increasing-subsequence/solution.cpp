class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int>st;
        st.insert(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>(*(--st.end()))){
                st.insert(nums[i]);
            }
            else{
                auto it=st.lower_bound(nums[i]);
                st.erase(it);
                st.insert(nums[i]);
            }
        }
        return st.size();
    }
};